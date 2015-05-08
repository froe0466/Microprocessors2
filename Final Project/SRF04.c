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

    TMR6 = 255;
    PORTAbits.RA3 = 1;
    
}
