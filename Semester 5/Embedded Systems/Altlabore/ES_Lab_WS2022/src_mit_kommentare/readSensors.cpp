#include "readSensors.h"

readSensors::readSensors() :
IR_front(P1_31),
IR_left(P0_26),
IR_right(P1_30),
IR_rear(P0_2),
ultrasonic(P0_27, P0_28, 0xE4),
ultrasonic2(P0_27, P0_28, 0xE2)
{
    ultrasonic.setRangeRegister(0x8C);
    ultrasonic.setMaxGainRegister(0x05);
}

/**
 * Note: If the sensor voltage is between 0..0.3V, an object is in front of the sensor
 *       If the sensor voltage is between 0.3..3.1V, an object is either in front of far away from the sensor
 *       If Output = 3.2V, Dist=3cm
 *       If Output = 2.7V, Dist=2.2cm or 4cm
 *       If Output = 2.2V, Dist=2cm or 5cm
 *       Below 2.2V Output is not traceable to distance :(
 *  basically: X = 9.3707*V^-0.889
*/
float readSensors::calculate_dist_from_IR(float voltage)
{
    // Function to calculate Infrared distance from signal value:
    /*
    Ich habe aus den Werten in dem IR Datenblatt in Excel eine Formel erzeugen lassen
    */
    float distance = pow(voltage, -0.889)*4.3707; 
    if(distance<0) return 70; // Unplausibler Wert
    if(distance>70) return 70; // 70 wird also als Maximalabstand festgelegt
    return distance;
}

float readSensors::get_IR_front() // Nutzen alle diesselbe Formel 
{
    float voltage = this->IR_front.read();
    return this->calculate_dist_from_IR(voltage);
}

float readSensors::get_IR_left()
{
    float voltage = this->IR_left.read();
    return this->calculate_dist_from_IR(voltage);
}

float readSensors::get_IR_right()
{
    float voltage = this->IR_right.read();
    return this->calculate_dist_from_IR(voltage);
}

float readSensors::get_IR_rear()
{
    float voltage = this->IR_rear.read();
    return this->calculate_dist_from_IR(voltage);
}

int readSensors::get_US()
{
    this->ultrasonic.startRanging(); //Messung starten
    this->ultrasonic2.startRanging();
    while((!this->ultrasonic.rangingFinished())&(!this->ultrasonic2.rangingFinished()))
    {
        //wait for ranging VON BEIDEN SENSOREN to be finished
    }
    return (this->ultrasonic.getRange()+this->ultrasonic2.getRange())/2; // Return avg. of both US Sensoren
}