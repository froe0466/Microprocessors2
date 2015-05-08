#define _XTAL_FREQ 10000000 //10MHz crystal
#include "config.h" //Header file for the configuration bits
#include "SRF04.h"

void SRF04_Setup(){

    TRISAbits.RA2 = 0;
    TRISAbits.RA3 = 1;

    TRISAbits.RA4 = 0;
    TRISAbits.RA5 = 1;

    LATAbits.LATA3 = 0;
    LATAbits.LATA5 = 0;


    T1CON = 0b00000000;
}

void Send_Pulse(void){

    TMR1H = 255;
    TMR1L = 253;

    PORTAbits.RA2 = 1;

    PIR1bits.TMR1IF = 0; //Clear Interrupt

    T1CONbits.TMR1ON = 1; //Start Running TMR6

    while(PIR1bits.TMR1IF == 0); //Wait for Interrupt

    T1CONbits.TMR1ON =0;
    PORTAbits.RA2 = 0;

    TMR1H = 0;
    TMR1L = 0;
}

void Measure_Pulse(void)
{
    T1CONbits.TMR1ON = 1; //Start Timer
    while(PORTAbits.RA3 = 0);
    T1CONbits.TMR1ON = 0; //Stop Timer

}
