#include <REGX52.H>

void TIMER_0_INIT()	//��ʱ��50΢��		
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x00;		
	TH0 = 0xDC;	
	TF0=0;
	TR0=1;
	EA=1;
	ET0=1;
	PT0=0;
}	


//void TIMER_0_ISR()   interrupt 1
//{
//			
//}	
