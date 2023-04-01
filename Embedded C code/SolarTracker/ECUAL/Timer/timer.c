/*
 * timer.c
 *
 * Created: 11-Oct-22 2:19:54 AM
 *  Author: ahmed
 */ 


#include "timer.h"

void TIMER_init(){
	TCCR0B = 0x00;
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TCCR1C = 0x00;

	
}

int overflows;
long overflows_10;
int overflowCounter;
long overflowCounter_10;
float Tmax;

void TIMER_delay(int millisec){ 
	TCCR1B |= (1<<0); //no prescalar (1)
    //Ttick = 0.0000625; //in ms
	//Tmax = Ttick * pow(2,16);   
	Tmax = 4.096; //seconds
	overflows = round(millisec/Tmax);
	overflowCounter = 0;
	
	/*the and condition breaks the timer if the button is pressed, thus you 
	 don't have to wait for the delay to finish so that the ISR is executed */
	while(overflowCounter < overflows){   
		while( (TIFR1 & (1<<0)) == 0 ); 
		//clear bit
		TIFR1 |= (1<<0);
		//Timer Stop
		overflowCounter++;
	}
	overflowCounter = 0;
			
	TCCR1B = 0x00;
}

void TIMER_delay_lin(float millisec){ 
	TCCR1B |= (1<<0); //no prescalar (1)
    //Ttick = 0.0000625; //in ms
	//Tmax = Ttick * pow(2,16);   
	Tmax = 4.096; //seconds
	overflows = ceil(millisec/Tmax);
	overflowCounter = 0;
	
	/*the and condition breaks the timer if the button is pressed, thus you 
	 don't have to wait for the delay to finish so that the ISR is executed */
	while(overflowCounter < overflows){   
		while( (TIFR1 & (1<<0)) == 0 ); 
		//clear bit
		TIFR1 |= (1<<0);
		//Timer Stop
		overflowCounter++;
	}
	overflowCounter = 0;
			
	TCCR1B = 0x00;
}

void TIMER_delay_10(long millisec){ 
	TCCR1B |= (1<<0); //no prescalar (1)
    //Ttick = 0.0000625; //in ms
	//Tmax = Ttick * pow(2,16);   
	Tmax = 4.096; //seconds
	overflows_10 = round((long)(millisec)/(Tmax));
	overflowCounter_10 = 0;
	
	/*the and condition breaks the timer if the button is pressed, thus you 
	 don't have to wait for the delay to finish so that the ISR is executed */
	while( overflowCounter_10 < overflows_10){   
		while( (TIFR1 & (1<<0)) == 0 ); 
		//clear bit
		TIFR1 |= (1<<0);
		//Timer Stop
		overflowCounter_10 = overflowCounter_10 +1;
	}
	overflowCounter_10 = 0;
			
	TCCR1B = 0x00;
}


	
	
	

	
