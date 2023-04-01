
/*
 * dio.h
 *
 * Created: 27-Nov-22 9:23:22 PM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Values defines
#define HIGH 1
#define LOW 0


void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);// Initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read dio



#endif /* DIO_H_ */