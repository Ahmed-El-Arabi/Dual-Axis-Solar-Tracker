/*
 * interrupts.h
 *
 * Created: 12-Oct-22 4:27:11 AM
 *  Author: ahmed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "registers.h"

//External interrupt request 1
#define EXT_INT_0 __vector_1

//External interrupt request 2
#define EXT_INT_1 __vector_2

//Enable interrupts

//Set Global Interrupts, Set the I-bit in status register to 1
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")

//Clear Global Interrupts, Set the I-bit in status register to 0
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//Rising edge ISC01 ISC00 are set to 1
#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)

//Enable external interrupt INT0
#define SETUP_INT0() GICR|=(1<<6)

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */