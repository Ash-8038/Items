#include <REGX52.H>

void TIMER0_INIT()
{
	TMOD&=0XF0;
	TMOD|=0X01;
	TH0=0;
	TL0=0;
	TF0=0;
	TR0=0;
	ET0=0;
}

void TIMER0_SetCounter(unsigned int value)
{
	TH0=value/256;
	TL0=value%256;
}
	
unsigned int TIMER0_GetCounter()
{
	unsigned int value;
	value=(TH0<<8)|TL0;
	return value;
	return (TH0<<8)|TL0;
}

void TIMER0_Run(unsigned char flag)
{
	if(flag)
		TR0=1;
	else
		TR0=0;
	TR0=flag;
}




















