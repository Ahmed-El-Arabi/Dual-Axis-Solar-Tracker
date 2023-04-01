
/*
 * app.h
 *
 * Created: 11-Oct-22 2:22:06 AM
 *  Author: ahmed
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../ECUAL/Stepper/stepper.h"
#include "../ECUAL/Timer/timer.h"
#include "../Utilities/interrupts.h"
#include "../ECUAL/Linear/linear.h"


double hourD = 11.6;
int days = 28;
#define lat  30.00409436499994
#define lon 31.70039206325549
#define GMT 2

void APP_init(void); // initializes all lights, timers, and interrupt registers needed
void APP_start(void); // main loop



#endif /* APPLICATION_H_ */

