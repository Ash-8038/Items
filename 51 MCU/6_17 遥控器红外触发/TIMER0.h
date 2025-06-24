#ifndef __TIMER0_H__
#define __TIMER0_H__

void TIMER0_INIT();

void TIMER0_SetCounter(unsigned int value);

unsigned int TIMER0_GetCounter();

void TIMER0_Run(unsigned char flag);


#endif