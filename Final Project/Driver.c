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

void main(void){

    /*NOTE:: You need to edit all of the Port Init functions to make sure that they do not overwrite each other!!*/
  /*
    EPWM_Port_Init();

    //ECCP1 Init Sequence
    EPWM1_Initialize();
    TMR2_Initialize();
    EPWM1_LoadDutyValue(60);
    Switch_Direction1();
    EPWM1_LoadDutyValue(60);
    
    //ECCP2 Init Sequence
    EPWM2_Initialize();
    TMR4_Initialize();
    EPWM2_LoadDutyValue(60);
    Switch_Direction2();
    EPWM2_LoadDutyValue(60);

    //LCD Init Sequence
    LCD_init(); //Initialize LCD
    place_lcd_cursor(0,0);
    LCD_write("Start");
*/
    //i2c Initialization
    i2c_Port_Init();
    i2c_Init();

    while(1)
    {
      //Ultrasonic Sensor - Echo Command & Read
      i2c_Command(0xE0,0x00,0x51);
      i2c_Read(0xE0,0x02);
    }
}
