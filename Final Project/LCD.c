/*
 * File:   LCDLab.c
 * Author: froe0466
 * Created on 4/11/2015
 * ENGR331 - Final Project
*/
#define _XTAL_FREQ 10000000 
#include "config.h"
#include "LCD.h"

/*******************************
 * Global variables
 ******************************/

//variable to keep track of the current Y value of the display
int yPos = 0;

void LCD_init(void)
{
    //Initialize Ports as 0
    LATCbits.LC3 = 0;
    LATCbits.LC2 = 0;
    LATCbits.LC4 = 0;
    LATCbits.LC5 = 0;
    LATCbits.LC6 = 0;
    LATCbits.LC7 = 0;

    //Set Ports as outputs
    TRISCbits.RC3 = 0;
    TRISCbits.RC2 = 0;
    TRISCbits.RC4 = 0;
    TRISCbits.RC5 = 0;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 0;

    // wait for Power on reset
    Delay100ms();

    //Hold RS in a low state
    PORTCbits.RC3 = 0;

    //Function Set in 8-bit mode
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x30; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Function Set in 8-bit mode
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x30; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Function Set in 8-bit mode
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x30; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //4-bit Initialization
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x20; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Function Set, specify display size and font
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x20; PORTCbits.RC2 = 0;
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x80; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Display ON
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x00; PORTCbits.RC2 = 0;
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0xF0; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Clear Display
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x00; PORTCbits.RC2 = 0;
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x10; PORTCbits.RC2 = 0;
    __delay_ms(10);
    
    //Entry Mode Set
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x00; PORTCbits.RC2 = 0;
    PORTCbits.RC2 = 1; PORTC = (PORTC & 0b00001111) | 0x60; PORTCbits.RC2 = 0;
    __delay_ms(10);

    //Set DDRAM Address
    place_lcd_cursor(0,0); 
}

void LCD_write(unsigned char data[])
{
    //Create a variable to track the yPos, this only works if we begin on line 0

    for(int i=0; data[i]!='\0'; i++)
    {
        if(data[i] == '\n')
        {
            // if we encounter a new line character, increment display line
            ++yPos;
            place_lcd_cursor(0,yPos);
        }
        else
        {
            // call our character writing function to display the next char
            LCD_writeChar(data[i]);
        }
    }
}


void LCD_writeChar(unsigned char data)
{
    //split incoming data into 2 seperate bytes
    unsigned char upper = data & 0b11110000;
    unsigned char lower = (data << 4);

    //clear pins and send upper and lower bytes using 4-bit interface
    LATCbits.LC3 = 1;
    LATCbits.LC2 = 1; LATC = (LATC & 0b00001111) | upper; LATCbits.LC2 = 0;
    LATCbits.LC2 = 1; LATC = (LATC & 0b00001111) | lower; LATCbits.LC2 = 0;
    __delay_ms(1);
    LATCbits.LC3 = 0;
}


void place_lcd_cursor(unsigned char x, unsigned char y)
{
    //Set global y value to set y value
    yPos = y;

    //calculate hex value of position based on x and y coords
    unsigned char position = (0x40*y)+x;
    LATCbits.LC3 = 0;

    //send upper bits to DDRM, making sure to set MSB to 1
    LATCbits.LC2 = 1;
    LATC = LATC & 0b00001111;
    LATC = (LATC | (position & 0b11110000)) | 0b10000000;
    LATCbits.LC2 = 0;

    //send lower bits to DDRM
    LATCbits.LC2 = 1;
    LATC = (LATC & 0b00001111) | (position << 4);
    LATCbits.LC2 = 0;
    __delay_ms(1);
}

void Delay100ms(void)
{   int i;
    for(i=0;i<100;i++)
    {
         __delay_ms(1); // built in delay function
		 // for other functions type __del and press CTRL & SPACE.
    }
}

