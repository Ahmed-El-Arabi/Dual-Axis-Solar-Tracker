/*
 * linear.c
 *
 * Created: 11-Dec-22 10:52:03 PM
 *  Author: ahmed
 */ 


#include "linear.h"

void LINEAR_init(uint8_t linearPort,uint8_t linearPin){
	
	DIO_init(linearPort,linearPin,OUT);

}

void LINEAR_on(uint8_t linearPort,uint8_t linearPin){
	
	DIO_write(linearPort,linearPin,HIGH);
	
}

void LINEAR_off(uint8_t linearPort,uint8_t linearPin){
	DIO_write(linearPort,linearPin,LOW);
}

void step_forward(float time){
	
	//Forward linear
	LINEAR_on(LINEAR_PORT,FORWARD_PIN);
	LINEAR_off(LINEAR_PORT,BACKWARD_PIN);
	TIMER_delay_lin(time);
	
	 //Stop linear
	LINEAR_off(LINEAR_PORT,FORWARD_PIN);
	LINEAR_off(LINEAR_PORT,BACKWARD_PIN);
}


void step_backward(float time){

	
	//backward linear
	LINEAR_off(LINEAR_PORT,FORWARD_PIN);
	LINEAR_on(LINEAR_PORT,BACKWARD_PIN);
	TIMER_delay_lin(time);
	
	//Stop linear
	LINEAR_off(LINEAR_PORT,FORWARD_PIN);
	LINEAR_off(LINEAR_PORT,BACKWARD_PIN);
}


//time 119s forward
//time 125s backward
//1s = 1.512mm
//1000ms = 0.152mm

void step_lin(float s){
	
	if(s<0){
		float stroke = floor((float) (fabs(s)*627.78));	
		step_backward(stroke);
		//TIMER_delay(3000);

}
	else{
		float stroke = floor((float) (fabs(s)*627.78));
		step_forward(stroke);
		//TIMER_delay(3000);
	}
}



