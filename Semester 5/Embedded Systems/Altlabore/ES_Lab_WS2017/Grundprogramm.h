#ifndef MAIN_H
#define MAIN_H

#include "mbed.h"
#include "Queue.h"
#include "cmsis_os.h"
#include "LCD_Touch_ILI9328.h"
#include "SRF08.h"
#include "Buttons.h"



/*****Pin Connections to**************/
/*****Data Bus, LCD, Touch**/

BusOut dataBus( p26, p25, p24, p23, p22, p21, P2_6, P2_7); // 8 pins
ILI9328_LCD lcd( P0_22, p15, P0_24, P0_21, P0_19, P0_20, &dataBus, P0_25 );// control pins and data bus  CS, RS, WR, DIR, EN, LE, DATA_PORT, RD
TouchScreenADS7843 touch(p5, p6, p7, p8, P2_13, &lcd);     // ADS7843 -> mosi, miso, sclk, cs, irq, SPI_TFT

/*Standard Koordinaten*/
int root_x=40;
int root_y=40;
uint16_t pwmMotor=1500;
uint16_t pwmServo=1500;
char array[100];


/*Funktion zum abrufen der Button States*/
void checkbuttons();

/*Deklaration Infrarot-Sensoren*/
AnalogIn Inf_vorne(P1_31);
AnalogIn Inf_hinten(P0_2);
AnalogIn Inf_links(P0_26);
AnalogIn Inf_rechts(P1_30);

/*Deklaration Ultraschallsensoren*/
SRF08 UsensorVoLi(P0_27, P0_28, 0xE0);    
SRF08 UsensorVoRe(P0_27, P0_28, 0xE4);

/*Struct für MessageQueue*/
typedef struct {  
    float_t     WertV;                                                                                                          
    float_t     WertH;
    float_t     WertL;
    float_t     WertR;
    uint32_t    WertVoRe;
    uint32_t    WertVoLi;

} message_t;

/* Queue für Werteübergabe */
MemoryPool <message_t, 1> mpool;
Queue <message_t, 1> queue;                   
  
/*Buttonerstellung */                                                   
Button Start,Drive;          


void TaskSensordaten();
void TaskAktoren();
void TaskAusgabe();
void TaskAktorTest();

/*Dden Threads die passende priorität gegeben*/
/*Da die Sensordaten und die Aktoren für die Regelung wichtig sind, kriegen sie eine hohe Priorität*/
/*Die Aktortest muss nicht im Vordergrund stehen.*/
/*Die Displayausgabe ist mit das unwichtigste und deshalb haben wir ihr eine niedrigere Priorität gegeben.*/     // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Thread thread_TaskSensordaten((osPriorityHigh));
Thread thread_TaskAktoren((osPriorityHigh));
Thread thread_TaskAusgabe((osPriorityNormal));
Thread thread_TaskAktorTest((osPriorityNormal));


#endif