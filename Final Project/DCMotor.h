/* 
 * File:   DCMotor.h
 * Author: froe0466
 *
 * Created on April 14, 2015, 9:58 AM
 */

#ifndef DCMOTOR_H
#define	DCMOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

void EPWM1_Initialize (void);
void EPWM1_LoadDutyValue(int dutyValue);
void TMR2_Initialize(void);
void Switch_Direction1(void);

void EPWM2_Initialize (void);
void EPWM2_LoadDutyValue(int dutyValue);
void TMR4_Initialize(void);
void Switch_Direction2(void);

void EPWM_Port_Init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DCMOTOR_H */

