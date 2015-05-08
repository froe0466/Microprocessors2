#define _XTAL_FREQ 10000000 //10MHz crystal
#include "config.h" //Header file for the configuration bits
#include "SRF04.h"

void SRF04_Setup(){

    TRISAbits.RA2 = 1;
    TRISAbits.RA3 = 0;

    TRISAbits.RA4 = 1;
    TRISAbits.RA5 = 0;

    LATAbits.LATA3 = 0;

    LATAbits.LATA5 = 0;

    T6CON = 0b00000000;

}

void Send_Pulse(void){

    //TMR6 = 255;
    PORTAbits.RA2 = 1;

   // PIR5bits.TMR6IF = 0; //Clear Interrupt

   // T6CONbits.TMR6ON = 1; //Start Running TMR6

    //while(PIR5bits.TMR6IF == 0); //Wait for Interrupt

    //T6CONbits.TMR6ON =0;

    __delay_us(10);

    PORTAbits.RA2 = 0;

   // TMR6 = 0;    
}

void Measure_Pulse(void)
{
    T6CONbits.TMR6ON = 1; //Start Timer
    while(PORTAbits.RA2 = 0);
    T6CONbits.TMR6ON = 0; //Stop Timer

}
