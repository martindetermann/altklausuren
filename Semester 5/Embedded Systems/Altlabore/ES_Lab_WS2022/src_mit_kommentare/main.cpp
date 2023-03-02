/******************************************************************************/
/*                                                                            */
/*              Ostfalia Hochschule für angewandte Wissenschaften             */
/*                        Fakultät für Fahrzeugtechnik                        */
/*           Institut für Fahrzeuginformatik und Fahrzeugelektronik           */
/*                             Fahrzeuginformatik                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Paket:        ES_LAB                                                       */
/* Modul:        ES_LAB_2                                                     */
/* Projekt:      ES_LAB_2                                                     */
/* Beschreibung: Labor 2   "Beispiel EventQueue"                              */
/*----------------------------------------------------------------------------*/
/* Datei:        'main.cpp'                                                   */
/*                                                                            */
/* Autoren:      Jan-Hendrik Aschen, M.Eng.                                   */
/*               Prof. Dr.-Ing. Volker von Holt                               */
/* Datum:        05.10.22                                                     */
/* Version:      0.3 / WS22/23                                                */
/******************************************************************************/
/* Gruppe         : 08                                                        */
/* Name           : Heinz-Walter Mustermann                                   */
/* Matrikelnummer : 01234567                                                  */
/* Name           : Maria Musterfrau                                          */
/* Matrikelnummer : 89101112                                                  */
/******************************************************************************/

//------------------------------------------------------------------------------
//  Headerdateien:
//------------------------------------------------------------------------------

//os 5.15

//#include "monitor.h"
#include "threadLocal.h"
#include "readSensors.h"

//#include "mbed.h"
#include "rtos.h"
#include "../LCD_Touch_ILI9328.h"

/**
 * 4-Tasks mit unterschiedlichen Prioritäten und Reservierte Speichergrößen, welche durch experimentieren
 * festgelegt wurden.
*/
Thread thread_Task_1(osPriorityHigh, 0.5*OS_STACK_SIZE,NULL,"Task1"); // Task 1 Thread mit default Einstellungen initialisieren
Thread thread_Task_2(osPriorityNormal, 0.5*OS_STACK_SIZE,NULL,"Task2"); // Task 2 Thread mit default Einstellungen initialisieren
Thread thread_Task_3(osPriorityNormal, 0.5*OS_STACK_SIZE,NULL,"Task3"); // Task 3 Thread mit default Einstellungen initialisieren
Thread thread_Task_4(osPriorityHigh, 0.5*OS_STACK_SIZE,NULL,"Task4"); // Task 4 Thread mit default Einstellungen initialisieren

/**
 * Einige Mutexe, mit unterschiedlichen Namen, im Interesse der Leserlichkeit im Code.
*/
Mutex us_data_mutex;
Mutex IR_data_mutex;
Mutex cycleTime_mutex;
Mutex testMode_mutex;
Mutex wait_mutex;
Mutex heap_stats_mutex;

/**
 * Die folgenden Variablen dienen zum Abspeichern der Sensorwerte (in cm), während das Programm 
 * läuft. Die Werte werden von der Sensorauswertung (Sensor) Task definiert, und von Motor- und 
 * Speedsteuerungs Tasks ausgewertet.
*/
static float IR_front_cm = 10; //IR=Infrarot
static float IR_left_cm = 10; 
static float IR_right_cm = 10;
static float IR_rear_cm = 10;
static int UltraSchall_cm = 101; //Durchschnittswert der beiden vorderen US Sensoren

/**
 * Counter zum Speichern der Anzahl von Zykluszeitüberschreitungen durch Rechnenvorgänge
 * innerhalb der Task. Überläufe die durch eine Überschreitung der Wartezeit geschehen
 * werden aktuell nicht gezählt.
*/
static int steering_cycleTime_exceeded=0; //bei Task Lenkungssteuerung
static int speed_cycleTime_exceeded=0; //bei Task Motorsteuerung
static int sensor_cycleTime_exceeded=0; //bei Task Sensorauswertung

/**
 * task_cycleTime speichert die Zeit (in ms) die für die Rechenleistung der Task verwendet wurde.
 * 
 * task_cycleTimeReal speichert die Zeit (in ms) die für die Rechenleistung + die Zeit (in ms) die für
 * das Warten verwendet wurde. Diese Zeit beschreibt also die gesamte (reale) Zykluszeit, inkl. Warten.
*/
static int steering_cycleTime = 0; //bei Task Lenkungssteuerung
static int steering_cycleTimeReal = 0; //bei Task Lenkungssteuerung
static int speed_cycleTime = 0; //bei Task Motorsteuerung
static int speed_cycleTimeReal = 0; //bei Task Motorsteuerung
static int sensor_cycleTime = 0; //bei Task Sensorauswertung
static int sensor_cycleTimeReal = 0; //bei Task Sensorauswertung
static int screen_cycleTime = 0; //bei Task Bildschirmsteuerung
static int screen_cycleTimeReal = 0; //bei Task Bildschirmsteuerung

/**
 * Die Heap Auslastung beinhaltet die Gesamte Speicherauslastung (also nicht nur heap, der Name ist
 * irreführend wir hatten es vorher anders deshalb der Name...)
 * Als Speicherauslastung wird der für alle Tasks (inkl. Main) reservierte Stack und Heap durch den 
 * gesamten Speicher geteilt.
 * heap_auslastung = 100*(reserved_stack+reserved_heap)/total_memory
 * Siehe threadLocal Klasse für genauere Details
*/
static double heap_auslastung = 0;

/**
 * Modi, die bestimmen in welchem Zustand sich das Programm aktuell befindet. Es ist die billige
 * Alternative zu einem Event Queue, um ein Antworten der Tasks auf Benutzereingabe zu ermöglichen.
*/
static int testMode=0; //0=test Modus nicht aktiviert, 1=aktiviert
static int stopPressed=1; //0=stop Modus nicht aktiviert, 1=aktiviert (test/folgefahrt halten)
static int autoMode=0; //0=auto (folgefahrt) Modus nicht aktiviert, 1=aktiviert

/**
 * Timer zur Bemessung der Zyklus- und Rechenleistungszeiten.
*/
Timer time_sensor_reading; //Für Task Sensorauswertung
Timer time_speed_control; //Für Task Motorsteuerung
Timer time_steering_control; //Für Task Lenksteuerung
Timer time_monitor_control; //Für Task Bildschirmsteuerung

//Bildschirm Sachen:
BusOut dataBus(p26,p25,p24,p23,p22,p21,P2_6,P2_7);  //Bus zur Übertragung von Daten vom uC zu Screen
ILI9328_LCD bildschirm(P0_22,p15,P0_24,P0_21,P0_19,P0_20, &dataBus, P0_25); //Der Bildschirm
TouchScreenADS7843 touch(P0_9, P0_8, P0_7, P0_6, P2_13, &bildschirm); //Draufgeklebte Touchscreen

/**
 * Buttons zur steuerung der verschiedenen Modi
*/
Button autoButton; //Auto Modus (Folgefahrt)
Button testLaufButton; //Test Modus
Button stopButton; //Stop Knopf

readSensors sensor_data; //Von uns definierte Klasse zur Auswertung von Sensordaten
threadLocal thread_manager; //Von uns definiterte Klasse zur Auswertung von Speicherlast

PwmOut motorOut(P1_21); //PIN als PWM Ausgabe konfiguriert, für Motor
PwmOut lenkungOut(P1_20); //PIN als PWM Ausgabe konfiguriert, für Lenkung

/**
 * Read Sensor Values ist die Task, die für das Einlesen der Sensordaten ist. Es werden folgende
 * Sensorwerte eingelesen:
 * -Infrarot Front, Heck, Links und Rechts
 * -Ultraschall Front (Links und Rechts)
 * Die Sensorrohwerte werden mit einem Objekt der readSensors Klasse ausgewertet und in der Funktion als 
 * globale static floats/ints gespeichert, von wo aus andere Funktionen darauf zugreifen können.
 * 
 * Zudem wird die Speicherauslastung mit einem Objekt der Klasse threadLocal ausgelesen und auch in globale
 * static ints gespeichert, wo sie von der screen Funktion ausgelesen werden können.
 * 
 * Es wird eine Zykluszeit von 100ms möglichst genau eingehalten
*/
void read_sensor_values()
{
    int tMeasure = 0;
    while(1)
    {
        time_sensor_reading.start(); // Zeitmessung beginnen
        IR_data_mutex.lock(); // Zugriff auf Sensorrohwerte-Variablen von anderen Threads blockieren
        IR_front_cm = sensor_data.get_IR_front(); // Abstände mithilfe des readSensor::sensor_data Obj. auslesen
        IR_left_cm = sensor_data.get_IR_left();
        IR_right_cm = sensor_data.get_IR_right();
        IR_rear_cm = sensor_data.get_IR_rear(); // liefert manchmal komische Werte, Ursache unbekannt
        IR_data_mutex.unlock(); // Zugriff für andere Threads wieder ermöglichen
        heap_stats_mutex.lock(); // Zugriff auf Speicherauslastung-Variable von anderen Threads blockieren
        heap_auslastung = thread_manager.get_stack_stats();
        heap_stats_mutex.unlock(); // Zugriff auf Speicherauslastung-Variable wieder ermöglichen
        us_data_mutex.lock(); // Zugriff auf Ultraschall-Variable von anderen Threads blockieren
        UltraSchall_cm = sensor_data.get_US(); // Abstände mithilfe des readSensor::sensor_data Obj. auslesen
        us_data_mutex.unlock(); // Zugriff wieder ermöglichen
        time_sensor_reading.stop(); // Zeitmessung pausieren (beinhaltet nur die Bearbeitungszeit, nicht sleep Zeit)
        tMeasure = time_sensor_reading.read_ms(); // Zeit für die Bearbeitung einlesen, speichern
        time_sensor_reading.start(); // Zeitmessung weiterführen
        cycleTime_mutex.lock(); // Zugriff cycleTime Variable des Sensors von anderen Threads blockieren
        sensor_cycleTime = tMeasure; // cycleTime bzw. Bearbeitungszeit hier speichern
        cycleTime_mutex.unlock(); // Zugriff auf cycleTime Variable wieder ermöglichen
        if(tMeasure > 100) // Prüfen ob Bearbeitungszeit die erlaubte maximale Zykluszeit überschritten hat (nicht gut wenn true)
        {
            cycleTime_mutex.lock(); // Zugriff auf Zyklusüberschreitungsvariable der Sensorauswertung von anderen Threads...
            sensor_cycleTime_exceeded++; // Zyklusüberschreitungsvariable der Sensorauswertung incrementieren
            cycleTime_mutex.unlock(); // ...
            tMeasure=99; // Die gemessene Zeit auf 99ms setzen, sodass 1ms gewartet wird und kein unplausibler wert entsteht in nächster Zeile
        }
        ThisThread::sleep_for(100-tMeasure); /* So lange warten, dass die gesamte Zykluszeit dieses Threads immer auf 100ms kommt (wenn keine Überschreitung durch Bearbeitung entsteht)*/
        time_sensor_reading.stop(); // Zeitmessung erneut pausieren
        cycleTime_mutex.lock(); // ...
        sensor_cycleTimeReal = time_sensor_reading.read_ms() +1; // Gesamte Zykluszeit, inkl. Warten einlesen, speichern
        cycleTime_mutex.unlock();
        time_sensor_reading.reset(); // Zeitmessung resetten (t=0ms)
    }
}

void control_speed()
{
    bool object=false; // Ein objekt wurde bereits erkannt (<1m Entfernung der US-Sensoren)
    int speed=1500; // Beinhaltet immer die, von der SW berechneten, soll-Geschwindigkeit
    int US_data = sensor_data.get_US(); // Beinhaltet eine lokale Kopie der US-Werte
    int cycleTime_measured = 0; // Zykluszeit (gemessen)
    int testModeActive=0; // Lokale Kopie der globalen Modus-Speicher variable
    int stop=1; // Lokale Kopie der globalen Modus-Speicher variable
    int autoModeL=0; // Lokale Kopie der globalen Modus-Speicher variable
    motorOut.period_ms(22); // siehe Datenblatt
    motorOut.pulsewidth_us(speed); // motor mit rpm=0 initialisieren 
    int testVar = 1500;
    while(1)
    {    
      testMode_mutex.lock(); // Modi aus den Globalen Variablen einlesen, lokal speichern
      stop = stopPressed;
      testModeActive = testMode;
      autoModeL = autoMode;
      testMode_mutex.unlock();
      time_speed_control.start(); 
      if((autoModeL)&&(!stop)&&(!testModeActive)) // Auto- (Folgefahrt-) Modus ist aktiv
      { 
        us_data_mutex.lock();
        US_data = UltraSchall_cm; // US Abstand aus der Globalen Variable einlesen, lokal speichern
        us_data_mutex.unlock();
        if(object) // Bed. 1: Ein objekt wurde bereits erkannt, bzw. US-Abstand war, seit Programmstart, mind. 1x kleiner als 1m
        {
            speed=1500+(US_data-5)*(5); // Formel die den Abstand auf den PWM-Bereich des Motors skaliert
            if(speed<1500) speed=1500; // um eine Abstandsabhängige Geschwindigkeit zu ermöglichen. Läuft gut!
            if(speed>2000) speed=2000; // Falls Formel einen zu hohen oder kleinen Wert liefert
        } else // Objekt wurde, seit Programmstart, noch nicht erkannt
        {
            if(US_data>100) // So lange sich kein Objekt innerhalb 1m des Sensors befindet...
            {
                motorOut.pulsewidth_us(1500); // ...stehen bleiben
            }
            if(US_data<100) // Sobald sich ein Objekt erstmalig innerhalb 1m des Sensors befindet...
            {
                motorOut.pulsewidth_us(2000); // ...vollgas geben
                object=true; // Lokal vermerken, dass ein Objekt nun erkannt wurde um nicht wieder in die Bedingung 1 zu kommen
            }
        }
        motorOut.pulsewidth_us(speed); // Berechnete Geschwindigkeit als PWM Signal, den Motor übergeben
    } else if((!autoModeL)&(!stop)&(testModeActive)) // Testmodus ist aktiv
    {  
        if(testVar > 1900) // Max. Geschwindigkeit von 2000 ist erreicht
        {
            testVar = 1500; // Bei rpm=0 anfangen
        } else // Max. Geschwindigkeit von 2000 ist nicht erreicht
        {
            testVar += 100; // Geschwindigkeit stufenweise erhöhen
        }
        motorOut.pulsewidth_us(testVar); // Berechnete Geschwindigkeit als PWM Signal, den Motor übergeben
    } else if((!autoModeL)&&(stop)&&(!testModeActive)) // Stop wurde gedrückt und ist aktiv
    {
        motorOut.pulsewidth_us(1500); // Stehen bleiben
    } else { // Ein massiver fehler ist aufgetreten, sodass keiner der Modi aktiv ist
        motorOut.pulsewidth_us(1200); // Rückwärts fahren
    }
    time_speed_control.stop();
    cycleTime_measured = time_speed_control.read_ms();
    time_speed_control.start();
    cycleTime_mutex.lock();
    speed_cycleTime = cycleTime_measured;
    cycleTime_mutex.unlock();
    if (cycleTime_measured>20)
    {
        cycleTime_mutex.lock();
        speed_cycleTime_exceeded++;
        cycleTime_mutex.unlock();
        cycleTime_measured = 19;
    }
    ThisThread::sleep_for(20 - cycleTime_measured);
    time_speed_control.stop();
    cycleTime_measured = time_speed_control.read_ms() +1;
    cycleTime_mutex.lock();
    speed_cycleTimeReal = cycleTime_measured;
    cycleTime_mutex.unlock();
    time_speed_control.reset();

  }
}

void control_steering()
{
    int angle=1500;
    int cycleTime_steering = 0;
    int left_IR = 0;
    int right_IR = 0;
    lenkungOut.period_ms(22);
    time_steering_control.start();
    int testModeActive = 0;
    int stop = 1;
    int autoModeL = 0;
    int testVar = 1000;
    while (1)
    {
        testMode_mutex.lock();
        stop = stopPressed;
        testModeActive = testMode;
        autoModeL = autoMode;
        testMode_mutex.unlock();
        time_steering_control.start();
        if((autoModeL)&&(!stop)&&(!testModeActive))
        {
            IR_data_mutex.lock();
            left_IR = IR_left_cm;
            right_IR = IR_right_cm;
            IR_data_mutex.unlock();
            if((left_IR > 20) && (right_IR > 20))
            {
                angle=1500;
            } else {
                //steering equation, similar to motor speed equation
                angle = (int) (1000 + (right_IR/left_IR)*500);
                if (angle>2000) angle = 2000;
            }
            lenkungOut.pulsewidth_us(angle);
        } else if((!autoModeL)&&(!stop)&&(testModeActive))
        { 
            if(testVar > 1800)
            {
                testVar = 1200;
            } else 
            {
                testVar += 200;
            }
            lenkungOut.pulsewidth_us(testVar);
        } else if((!autoModeL)&&(stop)&&(!testModeActive))
        {
            lenkungOut.pulsewidth_us(1500);
        } else {
            lenkungOut.pulsewidth_us(1500);
        }
        time_steering_control.stop();
        cycleTime_steering = time_steering_control.read_ms();
        time_steering_control.start();
        cycleTime_mutex.lock();
        steering_cycleTime = cycleTime_steering;
        cycleTime_mutex.unlock();
        if(cycleTime_steering > 20)
        {
            cycleTime_mutex.lock();
            steering_cycleTime_exceeded++;
            cycleTime_mutex.unlock();
            cycleTime_steering=19;
        }
        ThisThread::sleep_for(20-cycleTime_steering);
        time_steering_control.stop();
        cycleTime_mutex.lock();
        steering_cycleTimeReal = time_steering_control.read_ms() +1;
        cycleTime_mutex.unlock();
        time_steering_control.reset();
    }
}


void control_screen()
{
    bildschirm.Initialize(PORTRAIT_REV); // Portrait Modus
    bildschirm.FillScreen(COLOR_WHITE); // Weisser hintergrung (er ist trotzdem blau...)
    bildschirm.SetFont(&TerminusFont); // Font setzen
    touch.setCalibrationwithoutUser(); // "Kalibrierung ohne Nutzer durchführen"
    touch.TouchPanel_Calibrate(); // Kalibrierung durchführen (auskommentieren wenn nicht nötig)
    bildschirm.Print("Screen Ready", LEFT, 90, -1, -2, 0); // Anzeigen dass Initialisierung erfolgt ist
    testLaufButton.Create("test", 0, 20, &bildschirm, &touch, 70, 70); // Knöpfe constructen, anzeigen
    testLaufButton.Draw(); 
    autoButton.Create("auto", 78, 20, &bildschirm, &touch, 148, 70); // Auto=Folgefahrt Modus
    autoButton.Draw();
    stopButton.Create("stop", 156, 20, &bildschirm, &touch, 226, 70);
    stopButton.Draw();
    int exceededCycleTime = 0; // Zyklusüberschreitungen
    int cycleTime = 0; // Zeit die für die Bearbeitung benötigt wurde
    int cycleTime_adjusted = 0; // Zeit inkl. Warten 

    char sensorDataHeader[80]; // Char, in dem der Anzuzeigende Text gespeichert wird
    char test[3];
    sprintf(sensorDataHeader, "Sensor Data in cm");
    bildschirm.Print(sensorDataHeader, LEFT, 110, -1, -2, 0);
    char tasksHeader[80];
    sprintf(tasksHeader, "Tasks:");
    bildschirm.Print(sensorDataHeader, LEFT, 160, -1, -2, 0);
    sprintf(sensorDataHeader, "Name:tCycle:load:cyc.xceeded:");
    bildschirm.Print(sensorDataHeader, LEFT, 170, -1, -2, 0); 
    bildschirm.Print("USF", LEFT, 120, -1, -2, 0); 
    bildschirm.Print("IRF", 30, 120, -1, -2, 0);
    bildschirm.Print("IRL", 60, 120, -1, -2, 0);
    bildschirm.Print("IRR", 90, 120, -1, -2, 0);
    bildschirm.Print("IRH", 120, 120, -1, -2, 0);
    bildschirm.Print("Steer:", LEFT, 180, -1, -2, 0);
    bildschirm.Print("Speed:", LEFT, 190, -1, -2, 0);
    bildschirm.Print("Sensor:", LEFT, 200, -1, -2, 0); 
    bildschirm.Print("Screen:", LEFT, 210, -1, -2, 0);  
    bildschirm.Print("Speicherlast in %:", LEFT, 260, -1, -2, 0);
    int LUltraSchall_cm=0; // Lokale Kopien der Globalen Sensorwerte
    int LIR_front_cm=0;
    int LIR_left_cm=0;
    int LIR_right_cm=0;
    int LIR_rear_cm=0;
    while(1)
    {
        time_monitor_control.start();
        if ((stopPressed)&&(!testMode)&&(!autoMode)) // Stop gedrückt
        {
            bildschirm.Print("stop", LEFT, 280, -1, -2, 0); // Benutzer zeigen dass gedrückt wurde (2)
        } else if ((!stopPressed)&&(testMode)&&(!autoMode))
        {
            bildschirm.Print("test", LEFT, 280, -1, -2, 0);
        } else if ((!stopPressed)&&(!testMode)&&(autoMode)) 
        {
            bildschirm.Print("auto", LEFT, 280, -1, -2, 0);
        } else { // Ganz ernsthafter fehler, der eigentlich nicht auftreten kann
            bildschirm.Print("ERROR: MULTIMODE SELECTION", LEFT, 280, -1, -2, 0);
            ThisThread::sleep_for(1000); // Andere Threads weitermachen lassen
        }
        if (stopButton.GetButton_touched()) // Wenn Knöpfe gedrückt werden, nur die Knopf-bezogenen Funktionen ausführen (Zykluszeit sparen)
        {
            //DrawTouched führt zu einer hohen verzögerung der Zykluszeit, deshalb auskommentiert und mit (2) erzetzt
            //stopButton.DrawTouched(COLOR_BLACK, COLOR_RED, true);
            //stopButton.ResetButtonTouchedonlyStatus();
            testMode_mutex.lock();
            stopPressed = 1; // Globale Modusspeichervariablen setzen
            testMode = 0;
            autoMode = 0;
            testMode_mutex.unlock();
        } else if (testLaufButton.GetButton_touched())
        {
            //testLaufButton.DrawTouched(COLOR_BLACK, COLOR_RED, true);
            //testLaufButton.ResetButtonTouchedonlyStatus();
            testMode_mutex.lock();
            stopPressed = 0;
            testMode = 1;
            autoMode = 0;
            testMode_mutex.unlock();           
        }else if (autoButton.GetButton_touched())
        {
            //autoButton.DrawTouched(COLOR_BLACK, COLOR_RED, true);
            //autoButton.ResetButtonTouchedonlyStatus();
            testMode_mutex.lock();
            testMode = 0;
            stopPressed = 0;
            autoMode = 1;
            testMode_mutex.unlock();          
        } else  // Nur wenn Knöpfe nicht gedruckt werden, den Bildschirm aktualisieren (Zykluszeit sparen)
        {
            IR_data_mutex.lock();
            int LUltraSchall_cm=UltraSchall_cm;
            int LIR_front_cm=(int)IR_front_cm;
            int LIR_left_cm=(int)IR_left_cm;
            int LIR_right_cm=(int)IR_right_cm;
            int LIR_rear_cm=(int)IR_rear_cm;
            IR_data_mutex.unlock();
            sprintf(test, "%d", LUltraSchall_cm); // Sensorwerte anzeigen (gerundet um Platz zu sparen)
            bildschirm.Print(test, LEFT, 130, -1, -2, 0);   
            sprintf(test, "%d", (int)LIR_front_cm);
            bildschirm.Print(test, 30, 130, -1, -2, 0);   
            sprintf(test, "%d", (int)LIR_left_cm);
            bildschirm.Print(test, 60, 130, -1, -2, 0);   
            sprintf(test, "%d", (int)LIR_right_cm);
            bildschirm.Print(test, 90, 130, -1, -2, 0);   
            sprintf(test, "%d", (int)LIR_rear_cm);
            bildschirm.Print(test, 120, 130, -1, -2, 0);
            heap_stats_mutex.lock();
            sprintf(sensorDataHeader, "%d", (int)heap_auslastung); // Speicherauslastung anzeigen
            heap_stats_mutex.unlock();
            bildschirm.Print(sensorDataHeader, 170, 260, -1, -2, 0);
            cycleTime_mutex.lock(); 
            // Zykluszeiten anzeigen:
            sprintf(sensorDataHeader, "%dms, %d %%, %d", steering_cycleTimeReal, (int)100*steering_cycleTime/20, steering_cycleTime_exceeded);
            bildschirm.Print(sensorDataHeader, 50, 180, -1, -2, 0);
            sprintf(sensorDataHeader, "%dms, %d %%, %d", speed_cycleTimeReal, (int)100*speed_cycleTime/20, speed_cycleTime_exceeded);
            bildschirm.Print(sensorDataHeader, 50, 190, -1, -2, 0);
            sprintf(sensorDataHeader, "%dms, %d %%, %d", sensor_cycleTimeReal, (int)100*sensor_cycleTime/100, sensor_cycleTime_exceeded);
            bildschirm.Print(sensorDataHeader, 50, 200, -1, -2, 0);  
            cycleTime_mutex.unlock();
            sprintf(sensorDataHeader, "%dms, %d %%, %d", screen_cycleTimeReal, (int)100*cycleTime/300, exceededCycleTime);
            bildschirm.Print(sensorDataHeader, 50, 210, -1, -2, 0); 
        }
        time_monitor_control.stop();
        time_monitor_control.start();
        cycleTime_adjusted = time_monitor_control.read_ms(); // Bearbeitungszeit messen
        cycleTime = time_monitor_control.read_ms();
        if (cycleTime > 300) // Überschreitung der Zykluszeit ist geschehen
        {
            exceededCycleTime++;
            cycleTime_adjusted = 299;
        }
        ThisThread::sleep_for(300-cycleTime_adjusted); // Zykluszeit ist sicherheitshalber auf 300ms gesetzt, obwohl 250ms zu >99% eingehalten werden
        time_monitor_control.stop();
        cycleTime_mutex.lock();
        screen_cycleTimeReal = time_monitor_control.read_ms() +1; // Gesamtzeit messen
        cycleTime_mutex.unlock();
        time_monitor_control.reset();
    }
}

int main()
{

//calibrate motor (3.5 secs of rpm=0)
motorOut.period_ms(22);
motorOut.pulsewidth_us(1500);
ThisThread::sleep_for(3500);

thread_Task_1.start(callback(read_sensor_values));                               // Thread mit der Funktion Task_1 und dem Argument (void*)xy aufrufen

ThisThread::sleep_for(200); // Tasks genügend Zeit geben um sich initialisieren zu koennen

thread_Task_2.start(callback(control_speed));                               // Thread mit der Funktion Task_3 und dem Argument (void*)xy aufrufen

ThisThread::sleep_for(200);

thread_Task_3.start(callback(control_steering));                               // Thread mit der Funktion Task_3 und dem Argument (void*)xy aufrufen

ThisThread::sleep_for(200);

thread_Task_4.start(callback(control_screen));                               // Thread mit der Funktion Task_3 und dem Argument (void*)xy aufrufen


while(1) 
{
    ThisThread::sleep_for(1000); //um CPU Wach bleibt  
}

}

