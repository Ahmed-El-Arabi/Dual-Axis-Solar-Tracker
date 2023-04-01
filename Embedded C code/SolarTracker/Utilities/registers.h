
/*
 * registers.h
 *
 * Created: 30-Nov-22 1:49:03 AM
 *  Author: ahmed
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"
#include "bit_manipulation.h"
#include "interrupts.h"
#include <math.h>
#define PI 3.14159265359

//DIO Registers


//volatile as it may change from external signals

//Timer0 Registers
#define TCCR0B (*(volatile uint8_t*)(0x45))
#define TCCR1A (*(volatile uint8_t*)(0x80))
#define TCCR1B (*(volatile uint8_t*)(0x81))	
#define TCCR1C (*(volatile uint8_t*)(0x82))
#define TCNT1H (*(volatile uint8_t*)(0x85))
#define TCNT1L (*(volatile uint8_t*)(0x84))
#define TIFR1 (*(volatile uint8_t*)(0x36))
#define TIMSK1 (*(volatile uint8_t*)(0x6F))
#define TCNT1 (*(volatile uint8_t*)(0x1FF))



// PORTA registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)


// PORTB registers
#define PORTB *((volatile uint8_t*)0x25)
#define DDRB *((volatile uint8_t*)0x24)
#define PINB *((volatile uint8_t*)0x23)

// PORTC registers
#define PORTC *((volatile uint8_t*)0x28)
#define DDRC *((volatile uint8_t*)0x27)
#define PINC *((volatile uint8_t*)0x26)

// PORTD registers
#define PORTD *((volatile uint8_t*)0x2B)
#define DDRD *((volatile uint8_t*)0x2A)
#define PIND *((volatile uint8_t*)0x29)

//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//External Interrupts registers
#define MCUCR (*(volatile uint8_t*)(0x55))
//#define MCUCSR (*(volatile uint8_t*)(0x54))
#define SREG (*(volatile uint8_t*)(0x5F))
//#define GICR (*(volatile uint8_t*)(0x5B))
//#define GIFR (*(volatile uint8_t*)(0x5A))



#endif /* REGISTERS_H_ */