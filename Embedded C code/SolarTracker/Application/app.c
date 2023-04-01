/*
 * app.c
 *
 * Created: 11-Oct-22 2:21:58 AM
 *  Author: ahmed
 */ 

#include "app.h"
#include "../ECUAL/Stepper/stepper.h"
#include "../ECUAL/Linear/linear.h"
#include <math.h>

void APP_init(void){
	
	//Timer init
	TIMER_init();
	
	//Stepper motor 
	STEPPER_init(STEPPER_PORT,ENA_PIN); //Holding torque
	STEPPER_init(STEPPER_PORT,DIR_PIN); //Direction
	STEPPER_init(STEPPER_PORT,PUL_PIN); //Pulse
	DDRB = 0xFF;
	
	//Linear actuator
	LINEAR_init(LINEAR_PORT,FORWARD_PIN);
	LINEAR_init(LINEAR_PORT,BACKWARD_PIN);


    //Interrupt init
	sei(); //enable global interrupt



}



void APP_start(void){

	while(1){
		
// 		int i = 250;
// 		
// 		while(i>0){
// 		PORTB ^= (1<<0);
// 		TIMER_delay(20.48);//16
// 		PORTB ^= (1<<0);
// 		TIMER_delay(20.48);
// 		i--;
// 		}
// 		PORTB ^= (1<<0);
// 		TIMER_delay(5000);
		
// 		PORTB ^= (1<<0);
// 		TIMER_delay(10000);


 		//step_backward(50000);		                 //for setting up for the first time linear actuator must be fully retracted
		//TIMER_delay(6000);
		STEPPER_on(STEPPER_PORT,DIR_PIN);            //HIGH CCW
		//LINEAR_off(LINEAR_PORT,FORWARD_PIN);
		//LINEAR_off(LINEAR_PORT,BACKWARD_PIN); 
		 //first step which is used as a reference
		double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));		double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;float A = 21.6;float Beta = 17.1;float phi = elevation * PI/180;float alpha = pow(A,2) + pow(Beta,2);float beta = (float)2*A*Beta;

		
		
		
		if((HRA<0) && (hourD > sunrise && hourD < sunset)){
			
			float S = 10* (sqrt(alpha - (beta*cos(phi))) - 7.3);
			if(elevation>13 && elevation<81){
				step_lin(S);
			}
			double RefAzimuth = (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2);
			
			step(RefAzimuth);
			hourD += 0.166667;
			double sunrise2 = sunrise;
			double sunset2 = sunset; 
			double HRA2 = HRA;
			
			while((HRA2<0) && (hourD > sunrise2 && hourD < sunset2)){
				double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);
				double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);
				double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));
				double HRA = (15 * (LST - 12));
				double declination = (23.45 * sin(B * conv));			
				double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);
				double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);
				double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;float phi = elevation * PI/180;float alpha = pow(A,2) + pow(Beta,2);float beta = (float)2*A*Beta;
				float newS = 10* (sqrt(alpha - (beta*cos(phi))) - 7.3);
				float diffS = newS - S;
				S = newS;
				if(elevation>13 && elevation<81){
					step_lin(diffS);
				
				}
			
				double NewAzimuth = acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2;
			
				double diffAzi = NewAzimuth - RefAzimuth;
				RefAzimuth = NewAzimuth;
				step(diffAzi);
				hourD += 0.166667;
				double LSTM2 = 15 * GMT;
				double B2 = ((double)(360) / (double)(365)) * (days - 81);
				double EoT2 = 9.87 * sin(2 * B2 * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);
				double TC2 = EoT + (4 * (lon - LSTM2));
				double LST2 = hourD + ((double)(TC2) / (double)(60));
				double HRA2 = (15 * (LST2 - 12));
				double declination2 = (23.45 * sin(B2 * conv));			
				double sunrise2 = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination2 * conv)) * conv2) - (TC2 / 60);
				double sunset2 = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination2 * conv)) * conv2) - (TC2 / 60);
				if(HRA2>0){
					while(HRA2>0){
						double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;
						float phi =  -1*elevation * PI/180;
						float alpha = pow(A,2) + pow(Beta,2); //7
						float beta = (float)2*A*Beta;
						float newS = fabs(10* (sqrt(alpha - (beta*cos(phi))) - 7.3));
						float diffS = newS - S;
						S = newS;
						if(elevation>13 && elevation<81){
							step_lin(diffS);
						}
					
						double NewAzimuth2 = 360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2);
					
						double diffAzi1 = NewAzimuth2 - NewAzimuth;
						NewAzimuth = NewAzimuth2;
						step(diffAzi1);
						hourD += 0.166667;
						if(hourD > sunset){
							STEPPER_off(STEPPER_PORT,DIR_PIN); //CW
							double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);
							double finAzimuth = (360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2));
							step(finAzimuth);
							break;
						}
					}
					//break;
				}
			}
			
			
			
					
					
					
					
					
					
					
					
					while(HRA>0){
						double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;
						float phi =  -1*elevation * PI/180;
						float alpha = pow(A,2) + pow(Beta,2); //7
						float beta = (float)2*A*Beta;
						float newS = fabs(10* (sqrt(alpha - (beta*cos(phi))) - 7.3));
						float diffS = newS - S;
						S = newS;
						if(elevation>13 && elevation<81){
							step_lin(diffS);
						}
						double NewAzimuth = 360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2);
						double diffAzi = NewAzimuth - RefAzimuth;
						RefAzimuth = NewAzimuth;
						step(diffAzi);
						hourD += 0.166667;
						if(hourD > sunset){
							STEPPER_off(STEPPER_PORT,DIR_PIN); //CW
							double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);
							double finAzimuth = (360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2));
							step(finAzimuth);
							break;
						}
					}
				}
				
				
				//after 12:00 in solar time
				else if((HRA>0) && (hourD > sunrise && hourD < sunset)){
					float S = 10* (sqrt(alpha - (beta*cos(phi))) - 7.3);
					if(elevation>13 && elevation<81){
						step_lin(S);
					}
					double RefAzimuth = 360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2);
					step(RefAzimuth);
					hourD += 0.166667;
					
					while((HRA<0) && (hourD > sunrise && hourD < sunset)){
						double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));			double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;float phi = elevation * PI/180;float alpha = pow(A,2) + pow(Beta,2);float beta = (float)2*A*Beta;
						float newS = 10* (sqrt(alpha - (beta*cos(phi))) - 7.3);
						float diffS = newS - S;
						S = newS;
						if(elevation>13 && elevation<81){
							step_lin(diffS);
						}
						double NewAzimuth = acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2;
						double diffAzi = NewAzimuth - RefAzimuth;
						RefAzimuth = NewAzimuth;
						step(diffAzi);
						hourD += 0.166667;
					}
					
					while(HRA>0){
						double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;
						float phi =  -1*elevation * PI/180;
						float alpha = pow(A,2) + pow(Beta,2); //7
						float beta = (float)2*A*Beta;
						float newS = fabs(10* (sqrt(alpha - (beta*cos(phi))) - 7.3));
						float diffS = newS - S;
						S = newS;
						if(elevation>13 && elevation<81){
							step_lin(diffS);
						}
						double NewAzimuth = 360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2);
						double diffAzi = NewAzimuth - RefAzimuth;
						RefAzimuth = NewAzimuth;
						step(diffAzi);
						hourD += 0.166667;
						if(hourD > sunset){
							STEPPER_off(STEPPER_PORT,DIR_PIN); //CW
							double LSTM = 15 * GMT;double B = ((double)(360) / (double)(365)) * (days - 81);double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);double TC = EoT + (4 * (lon - LSTM));double LST = hourD + ((double)(TC) / (double)(60));double HRA = (15 * (LST - 12));double declination = (23.45 * sin(B * conv));double elevation = asin(((sin(declination * conv) * sin(lat * conv)) + (cos(declination * conv) * cos(lat * conv) * cos(HRA * conv)))) * conv2;double sunrise = 12 - ((double)1 / (double)15) * (acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);double sunset = 12 + (((double)1 / (double)15) * acos(-tan(lat * conv) * tan(declination * conv)) * conv2) - (TC / 60);
							double finAzimuth = (360 - (acos(((sin(declination * conv) * cos(lat * conv)) - (cos(declination * conv) * sin(lat * conv) * cos(HRA * conv))) / (cos(elevation * conv))) * conv2));
							step(finAzimuth);
							break;
						}
					}
				}
		
				
				
				while(hourD < sunrise || hourD > sunset){
					if(floor(hourD) ==24){
						days+=1;
						hourD = 0;
						TIMER_delay_10(600000); //10 minutes delay
		
					}
					else{
						TIMER_delay_10(600000); //10 minutes delay
						hourD += 0.166667;
					}
				}
				
				
				

}
}

