#include "Grundprogramm.h"

/********************************************/
/* Labor ES Wintersemester 2017/2018        */
/*Teilnehmer 1: Nasfi,Ilyes 70454899        */
/*Teilnehmer 2: Umar, Alexander 70426865    */
/*Aufgabe: Folgefahrt                       */
/*Version: 1.0                              */
/********************************************/


Timer t;                         //Timer für Zeitmessungen Sensorik
Timer t1;                        // Timer für Zeitmessung der Aktorik
char timer_t[100];               //Erzeugung des Arrays zur Displayausgabe des Timers Sensorik
char timer1_t [100];             //Erzeugng der Arrays zur Displayausgabe des Timers Aktorik
bool drive=false;


/*Deklaration der Outputs*/

PwmOut lenkung(P1_20);                                                             
PwmOut motor(P1_21);
int timer_wait;      
int timer1_wait;                                                          


int main() {
    
t.start();
t1.start();

Thread::wait(500);   
    
/*Einstellen der Registereinstellungen der Ultraschallschensoren*/
/*Verstärkung=94                                               */
/*Rangeregister(24)=^1,075m                                     */
    
UsensorVoLi.setRangeRegister(24);                                                   
UsensorVoRe.setRangeRegister(24);
UsensorVoLi.setMaxGainRegister(0x09);
UsensorVoRe.setMaxGainRegister(0x09);


/*Standard Initialisierung Display*/
lcd.Initialize(PORTRAIT_REV);
lcd.FillScreen(COLOR_WHITE);
lcd.SetFont(&TerminusFont);
touch.TouchPanel_Calibrate();

/*Initialisierung der PWM-Signale*/
lenkung.period_ms(22);
lenkung.pulsewidth_us(1500);
motor.period_ms(22);
motor.pulsewidth_us(1500);


/*Erstellen der Buttons Start & Drive                        */
/*"Beschriftung",x1,y2,&lcd,&touch,x2,y2                   */
/*Button wird zwischen X1 und X2 und Y1 und Y2 aufgespannt  */
Start.Create("Start",root_x+0,root_y+110,&lcd,&touch,root_x+50,root_y+160);
Drive.Create("Drive",root_x+100,root_y+110,&lcd,&touch,root_x+150,root_y+160);
Start.Draw();
Drive.Draw();

/*Zusatzvariable 'drive' zum Wechsel zwischen Betriebsmodi                */
/*drive==false                                                            */
/*Startbildschirm und Testen der Aktoren & Sensoren                       */
/*drive==true                                                             */
/*Modus: Folgefahrt                                                       */                                               
/*While-Schleife für Start-Bildschirm und Test der Aktoren & Sensoren     */

while(drive==false) 
{
    
    
    if(Start.GetButton_touched())                                                    
    {
        Start.DrawTouched();
        thread_TaskAusgabe.start(TaskAusgabe);                   
        thread_TaskSensordaten.start(TaskSensordaten);               
        thread_TaskAktorTest.start(TaskAktorTest);                                          
        drive=true;  
        Start.ResetButtonTouched();          
    }
    
}

/*While-Schleife für Folgefahrt*/

 while(drive==true)
{
    if(Drive.GetButton_touched())
    {
        Drive.DrawTouched();
        thread_TaskAktorTest.terminate();                                                    
        thread_TaskAktoren.start(TaskAktoren);                      
        Drive.ResetButtonTouched();
          while(1)
        {
            }
    }         
}

}

/*Funktion zum Auslesen der Sensordaten alle 100ms*/
/*Dauer 100ms*/

void TaskSensordaten()                                                
{
    message_t *message;                                                             //Pointer zur Übergabe des Datentyps message_t
    while(1)
    {
    t.reset();
    message->WertV = Inf_vorne.read();                                                //einlesen der Infrarot Sensoren
    message->WertH = Inf_hinten.read();
    message->WertL = Inf_links.read();
    message->WertR = Inf_rechts.read();                                              
    
    UsensorVoLi.startRanging();                                                      //Einlesen der Sensordaten für Ultraschall Sensoren
    UsensorVoRe.startRanging();                                                      
    
    Thread::wait(60);                                                               // Warte auf Abschließen der Messung
    
    message->WertVoLi = UsensorVoLi.getRange();                                      //Überschreiben der Sensordaten
    Thread::wait(20);                                                               
    message->WertVoRe = UsensorVoRe.getRange();                                      
    
    timer_wait=t.read_ms();
    timer_wait=100-timer_wait;
    Thread::wait(timer_wait);
    sprintf(timer_t,"Timer_Sen:%d",t.read_ms());
    
    queue.put(message);                                                         
    }

}

/*Hier werden die Aktoren alle 20ms angesteuert */
void TaskAktoren()                                                        
{    
int Wert,Wert1;
    
    lenkung.pulsewidth_us(1500);                                                    //Anfangswerte für die Lenkung
    motor.pulsewidth_us(1500);                                                      //Anfangswerte für Motor
    
        
    while(1)
    {
        osEvent evt = queue.get(0);                                                  //Auftritt eines Events
    
        if (evt.status == osEventMessage) 
            {
            t1.reset(); 
            message_t *message = (message_t*)evt.value.p;
            Wert=message->WertVoLi;                                                //Zuweisung der Werte auf oben definierte Variablen
            Wert1=message->WertVoRe;
            
                if(Wert <= 20 || Wert1 <= 20 || Wert > 100 || Wert1 > 100)        //Geschwindigkeit abhängig vom Abstand 
                {
                motor.pulsewidth_us(1500);
                }else
                if((Wert <= 100 || Wert1 <= 100) && (Wert > 90 || Wert1 > 90))
                {
                motor.pulsewidth_us(2000);
                }else
                if((Wert <= 90 || Wert1 <= 90) && (Wert > 80 || Wert1 > 80))
                {
                motor.pulsewidth_us(1950);
                }else
                if((Wert <= 80 || Wert1 <= 80) && (Wert > 70 || Wert1 > 70))
                {
                motor.pulsewidth_us(1900);
                }else
                if((Wert <= 70 || Wert1 <= 70) && (Wert > 60 || Wert1 > 60))
                {
                motor.pulsewidth_us(1850);
                }else
                if((Wert <= 60 || Wert1 <= 60) && (Wert > 50 || Wert1 > 50))
                {
                motor.pulsewidth_us(1800);
                }else
                if((Wert <= 50 || Wert1 <= 50) && (Wert > 40 || Wert1 > 40))
                {
                motor.pulsewidth_us(1750);
                }else
                if((Wert <= 40 || Wert1 <= 40) && (Wert > 30 || Wert1 > 30))
                {
                motor.pulsewidth_us(1700);
                }else
                if((Wert <= 30 || Wert1 <= 30) && (Wert > 20 || Wert1 > 20))
                {
                motor.pulsewidth_us(1650);
                }
    timer1_wait=t1.read_ms();
    timer1_wait=20-timer1_wait;
    Thread::wait(timer1_wait);
    sprintf(timer1_t,"Timer_Akt:%d",t1.read_us()); 
            } 
            else
            {}

    }
                                                                                   
    
}
/*Ausgabe der Messwerte der Sensoren */
void TaskAusgabe()                                                       
{
    char arrayV[100];                                                               //Erzeugung der Arrays für die Displayausgabe
    char arrayH[100];
    char arrayL[100];
    char arrayR[100];
    char arrayVoLi[100];
    char arrayVoRe[100];
    
    while(1)
    {
        
    Thread::wait(100);                                                              //Wartezeit der Task Ausgabe im Fahrmodus
    
    osEvent evt = queue.get();                                                      
    
    if (evt.status == osEventMessage)                                               //Auftritt des Events
    {
         message_t *message = (message_t*)evt.value.p;                              
         sprintf(arrayV,"Sensor Vorne: %f"   , message->WertV);                     //Schreiben der Sensordaten in die Arrays
         sprintf(arrayH,"Sensor Hinten: %f"   , message->WertH);
         sprintf(arrayL,"Sensor Links: %f"   , message->WertL);
         sprintf(arrayR,"Sensor Rechts: %f"   , message->WertR);
         sprintf(arrayVoLi,"UltraS Vorne Links: %d  "   , message->WertVoLi);
         sprintf(arrayVoRe,"UltraS Vorne Rechts: %d  "   , message->WertVoRe);
    }
    
    
    lcd.Print(arrayV,1,1,COLOR_RED,COLOR_BLACK);                                    //Ausgabe der Arrays(Sensordaten) auf dem Bildschirm
    lcd.Print(arrayH,1,11,COLOR_RED,COLOR_BLACK);
    lcd.Print(arrayL,1,21,COLOR_RED,COLOR_BLACK);
    lcd.Print(arrayR,1,31,COLOR_RED,COLOR_BLACK);
    lcd.Print(arrayVoLi,1,41,COLOR_RED,COLOR_BLACK);
    lcd.Print(arrayVoRe,1,51,COLOR_RED,COLOR_BLACK);
    lcd.Print(timer_t,1,61,COLOR_RED,COLOR_BLACK);
    lcd.Print(timer1_t,1,71,COLOR_RED,COLOR_BLACK);
    }
}

/*Ansteuerung der Lenkung nach der Bedienung des Start-Buttons*/
void TaskAktorTest()                                                         
{
    Thread::wait(800);
    motor.pulsewidth_us(1100);
    Thread::wait(800);
    motor.pulsewidth_us(1500);
    Thread::wait(500);
    motor.pulsewidth_us(1650);
    Thread::wait(500);
    lenkung.pulsewidth_us(1800);
    motor.pulsewidth_us(1800);
    Thread::wait(500);
    lenkung.pulsewidth_us(1950);
    motor.pulsewidth_us(2000);
    Thread::wait(500);
    lenkung.pulsewidth_us(1800);
    motor.pulsewidth_us(1800);
    Thread::wait(500);
    lenkung.pulsewidth_us(1500);
    motor.pulsewidth_us(1600);
    Thread::wait(500);
    lenkung.pulsewidth_us(1300);
    motor.pulsewidth_us(1500);
    Thread::wait(500);
    lenkung.pulsewidth_us(1050);
    Thread::wait(500);
    lenkung.pulsewidth_us(1300);
    Thread::wait(500);
    lenkung.pulsewidth_us(1500);

}


