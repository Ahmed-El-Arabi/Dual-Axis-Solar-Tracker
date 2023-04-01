#pragma once

#ifndef SERVER
#define SERVER


#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>






#define step 60*10
#define tDays 365.25
#define pressure 1015.2 //average barometric pressure in mbar Cairo, Egypt
#define T 25
#define timeZone 2 //GMT +2
#define PI 3.14159265
#define conv 0.01745329252 
#define w 360/365
#define conv2 57.29577951
//#define φ  30.00409436499994
//#define l 31.70039206325549 
//#define GMT 2
//int julianDay(int year, int month, double day, int B);

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

#endif 