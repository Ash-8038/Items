#include <REGX52.H>

void TIMER_0_INIT()	//¶¨Ê±Æ÷50Î¢Ãë		
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x9C;		
	TH0 = 0xFF;	
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
