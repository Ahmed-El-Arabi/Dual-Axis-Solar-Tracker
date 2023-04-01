/*
 * linear.h
 *
 * Created: 11-Dec-22 10:52:13 PM
 *  Author: ahmed
 */ 



#ifndef LINEAR_H_
#define LINEAR_H_

#include "../../MCAL/DIO driver/dio.h"


#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

#define LINEAR_PORT PORT_C
#define FORWARD_PIN PIN5
#define BACKWARD_PIN PIN4

//Motor time stroke = 2 mins 9s
//length 

#define LOW		0
#define HIGH	1

void LINEAR_init(uint8_t linearPort, uint8_t linearPin);

void LINEAR_on(uint8_t linearPort,uint8_t linearPin);

void LINEAR_off(uint8_t linearPort,uint8_t linearPin);

void step_forward(float time);

void step_backward(float time);

void step_lin(float s);

#endif