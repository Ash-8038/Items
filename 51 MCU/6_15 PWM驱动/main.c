#include <REGX52.H>
#include <TIMER_0.H>
#include <LCD.H>
#include <key.H>
unsigned char count,compare;
unsigned char number=0;
unsigned char keynumber=0;

void main()
{
	TIMER_0_INIT();
	while(1)
	{
		keynumber=key();
		if(keynumber)
		{
			number++;
			number%=4;
		}
		LCD(1,number);
		if(number==0)
			compare=0;
		if(number==1)
			compare=50;
		if(number==2)
			compare=75;
		if(number==3)
			compare=100;
	}
}

void TIMER_0_ISR()   interrupt 1
{
	TL0 = 0x9C;		
	TH0 = 0xFF;	
	count++;
	count%=100;
	if(count<compare)
		P1_0=1;
	else
		P1_0=0;
	
}	
