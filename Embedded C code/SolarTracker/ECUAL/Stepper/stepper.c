
/*
 * stepper.c
 *
 * Created: 30-Nov-22 3:27:13 AM
 *  Author: ahmed
 */ 


#include "stepper.h"

void convert(double hourD) {

	double fractPart, hour,m,sec,fractM,fractS,min;
	
	fractM = modf(hourD, &hour); 

	m = fractM * 60; 

	fractS = modf(m, &min);

	sec = (60 * fractS); 
}

void STEPPER_init(uint8_t stepPort,uint8_t stepPin){
	DIO_init(stepPort,stepPin,OUT);
}

void STEPPER_on(uint8_t stepPort,uint8_t stepPin){
	DIO_write(stepPort,stepPin,HIGH);
}

void STEPPER_off(uint8_t stepPort,uint8_t stepPin){
	DIO_write(stepPort,stepPin,LOW);
}

void step(double angle){
	long i = round(angle/0.0247875);
	//int i = 400;
	long j = i;
	long pulse10 = 16;
	int pulse = 16;


		
	//Azimuth
		
	while(i>0){
 
		STEPPER_on(STEPPER_PORT,PUL_PIN);
		PORTB ^= (1<<0);
		TIMER_delay(pulse);
		STEPPER_off(STEPPER_PORT,PUL_PIN);
		PORTB ^= (1<<0);
		TIMER_delay(pulse); 
		i--;
		
}
	
	PORTB ^= (1<<0);
	long afterStep = 600000 - (j * pulse * 2);
	TIMER_delay_10(afterStep);
	PORTB ^= (1<<0);



}


