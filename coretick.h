//ARMduino port for ARM family of Cortex-M chips
//software environment: gcc-arm


#ifndef _CORETICK_H
#define _CORETICK_H

#include "gpio.h"										//we use stm32f10x

//global defines

//global variables
//initialize the timer
void coretick_init(void);

//return dwt cycle count
#define ticks()			(DWT->CYCCNT)

//ticks per us - arduino styled function
#define cyclesPerMillisecond()		(F_CPU / 1000ul)
#define cyclesPerMicrosecond()		(F_CPU / 1000000ul)
#define millis()					(ticks() / cyclesPerMicrosecond())
#define micros()					(ticks() / cyclesPerMicrosecond())

//precision delays using ticks()
void coretick_delayms(uint32_t ms);
void coretick_delayus(uint32_t us);

#endif
