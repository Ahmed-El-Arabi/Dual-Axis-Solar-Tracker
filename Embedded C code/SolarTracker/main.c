/*
 * SolarTracker.c
 *
 * Created: 27-Nov-22 9:20:58 PM
 * Author : ahmed
 */ 

#include <avr/io.h>
#include "ECUAL/Stepper/stepper.h"
#define F_CPU 16000000UL

int main(void)
{

	APP_init();
	
	//Main loop
	while(1){
		
		APP_start();
	}
	
}
