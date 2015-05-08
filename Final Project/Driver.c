/*
 * File:   Driver.c
 * Author: froe0466
 * Created on 4/13/2015
 * ENGR331 - Final Project
 * This code is the main driver of the robot and
 * controls the functionality and integration with
 * the motors and sensors
*/
#define _XTAL_FREQ 10000000 //10MHz crystal
#include "config.h"
#include "LCD.h"
#include "DCMotor.h"
#include "i2c.h"
#include "LineSensor.h"

void main(void){

    //ECCP Port Initialization
    EPWM_Port_Init();

    //ECCP1 Init Sequence
    EPWM1_Initialize();
    TMR2_Initialize();

    //ECCP2 Init Sequence
    EPWM2_Initialize();
    TMR4_Initialize();

    Stop();

    //LCD Init Sequence
    LCD_init();
    place_lcd_cursor(0,0);

    //i2c Initialization
    i2c_Port_Init();
    i2c_Init();

    //Line Sensor Initialization
    lineSensor_init();

   //Confirm that the Robot Initialization is complete
    LCD_write("Start");

    Drive_Forward(400,45);



    while(1)
    {
        



        /*
        EPWM1_LoadDutyValue(60);
        Switch_Direction1();
        EPWM1_LoadDutyValue(60);

        EPWM2_LoadDutyValue(60);
        Switch_Direction2();
        EPWM2_LoadDutyValue(60);

          //Ultrasonic Sensor - Echo Command & Read
          i2c_Command(0xE0,0x00,0x51);
          i2c_Read(0xE0,0x02);

        //Read Line Sensor
        place_lcd_cursor(5,1);
        LCD_convertWrite(lineSensor_read(0));
       
        //Line Sensor True or False
        if(lineSensor_isWhiteLine1())
        {
            place_lcd_cursor(8,1);
            LCD_writeChar('T');
        }
        else
        {
            LCD_writeChar('F');
        }
        */
    }

}
