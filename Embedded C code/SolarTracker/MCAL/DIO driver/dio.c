
/*
 * dio.c
 *
 * Created: 27-Nov-22 9:23:07 PM
 *  Author: ahmed
 */ 

#include "dio.h"

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction){
	switch(portNumber){
		
		
		case PORT_A:
		if(direction == IN){
			DDRA &= ~(1<<pinNumber); //input
		}
		else if(direction == OUT)
		{
			DDRA |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
		
		
		case PORT_B:
		if(direction == IN){
			DDRB &= ~(1<<pinNumber); //input
		}
		else if(direction == OUT)
		{
			DDRB |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
		
		
		case PORT_C:
		if(direction == IN){
			DDRC &= ~(1<<pinNumber); //input
		}
		else if(direction == OUT)
		{
			DDRC |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
		
		
		case PORT_D:
		if(direction == IN){
			DDRD &= ~(1<<pinNumber); //input
		}
		else if(direction == OUT)
		{
			//
			DDRD |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
	}
}
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	switch(portNumber){
		case PORT_A :
		if(value == LOW){
			PORTA &= ~(1<<pinNumber); //input
		}
		else if(value == HIGH)
		{
			PORTA |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		case PORT_B :
		if(value == LOW){
			PORTB &= ~(1<<pinNumber); //input
		}
		else if(value == HIGH)
		{
			PORTB |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		case PORT_C :
		if(value == LOW){
			PORTC &= ~(1<<pinNumber); //input
		}
		else if(value == HIGH)
		{
			PORTC |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
		case PORT_D :
		if(value == LOW){
			PORTD &= ~(1<<pinNumber); //input
		}
		else if(value == HIGH)
		{
			PORTD |= (1<<pinNumber); //output
		}
		else{
			//error
		}
		break;
		
	}
}
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber){ // toggle dio
	switch(portNumber){
		case PORT_A:
		PORTA ^= (1<<7); //This line serves no function but it was added as the code for some reason skipped the first line, so I added anything here as it is already skipped
		PORTA ^= (1<<pinNumber);
		break;
		
		case PORT_B:
		PORTB ^= (1<<pinNumber);
		break;
		
		case PORT_C:
		PORTC ^= (1<<pinNumber);
		break;
		
		case PORT_D:
		PORTD ^= (1<<pinNumber);
		break;
	}
}
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read dio (this function was not used)
