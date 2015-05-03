/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC18F45K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set P2A aliases
#define P2A_TRIS               TRISC1
#define P2A_LAT                LATC1
#define P2A_PORT               PORTCbits.RC1
#define P2A_SetHigh()    do { LATC1 = 1; } while(0)
#define P2A_SetLow()   do { LATC1 = 0; } while(0)
#define P2A_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define P2A_GetValue()         PORTCbits.RC1
#define P2A_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define P2A_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set P1A aliases
#define P1A_TRIS               TRISC2
#define P1A_LAT                LATC2
#define P1A_PORT               PORTCbits.RC2
#define P1A_ANS                ANSC2
#define P1A_SetHigh()    do { LATC2 = 1; } while(0)
#define P1A_SetLow()   do { LATC2 = 0; } while(0)
#define P1A_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define P1A_GetValue()         PORTCbits.RC2
#define P1A_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define P1A_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define P1A_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define P1A_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set P2B aliases
#define P2B_TRIS               TRISD2
#define P2B_LAT                LATD2
#define P2B_PORT               PORTDbits.RD2
#define P2B_ANS                ANSD2
#define P2B_SetHigh()    do { LATD2 = 1; } while(0)
#define P2B_SetLow()   do { LATD2 = 0; } while(0)
#define P2B_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define P2B_GetValue()         PORTDbits.RD2
#define P2B_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define P2B_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define P2B_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define P2B_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set P1B aliases
#define P1B_TRIS               TRISD5
#define P1B_LAT                LATD5
#define P1B_PORT               PORTDbits.RD5
#define P1B_ANS                ANSD5
#define P1B_SetHigh()    do { LATD5 = 1; } while(0)
#define P1B_SetLow()   do { LATD5 = 0; } while(0)
#define P1B_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define P1B_GetValue()         PORTDbits.RD5
#define P1B_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define P1B_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define P1B_SetAnalogMode()   do { ANSD5 = 1; } while(0)
#define P1B_SetDigitalMode()   do { ANSD5 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/