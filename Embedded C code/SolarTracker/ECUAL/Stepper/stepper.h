
/*
 * stepper.h
 *
 * Created: 30-Nov-22 3:27:26 AM
 *  Author: ahmed
 */ 


#ifndef SERVER
#define SERVER

#include "../../MCAL/DIO driver/dio.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

//#define step 60*10
#define tDays 365.25
#define pressure 1015.2 //average barometric pressure in mbar Cairo, Egypt
//#define T 25
#define timeZone 2 //GMT +2
#define PI 3.14159265
#define conv 0.01745329252
#define w 360/365
#define conv2 57.29577951


#define STEPPER_PORT PORT_D
#define ENA_PIN PIN1
#define DIR_PIN PIN2
#define PUL_PIN PIN3

#define LOW		0
#define HIGH	1

void STEPPER_init(uint8_t stepPort, uint8_t stepPin);

void STEPPER_on(uint8_t stepPort,uint8_t stepPin);

void STEPPER_off(uint8_t stepPort,uint8_t stepPin);

void step(double angle);

void convert(double hourD);
#endif