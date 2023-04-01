/*
 * timer.h
 *
 * Created: 11-Oct-22 2:20:03 AM
 *  Author: ahmed
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include <math.h>





//set timer initial value
void Timer_init();

void TIMER_delay(int millisec); //delay of specific amount default uses 256 prescalar

void TIMER_delay_lin(float millisec); //delay for linear actuator timer

void TIMER_delay_10(long millisec); //delay of specific amount default uses 256 prescalar

#endif /* TIMER_H_ */
