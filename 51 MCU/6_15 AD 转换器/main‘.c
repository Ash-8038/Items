#include <REGX52.H>
#include <ADC.H>
#include <LCD.H>
#include <Delay.h>
#include <TIMER_0.h>
//5v参考电压，12位分辨率。
unsigned int XPT2046_Data;
unsigned char Data;
void main()
{
	TIMER_0_INIT();
	while(1)
	{
		XPT2046_Data=XPT2046_READ(XPT2046_XP1);
//		Data=XPT2046_Data%10;
//		LCD(4,Data);
//		Delay1();
//		Data=(XPT2046_Data/10)%10;
//		LCD(3,Data);
//		Delay1();
//		Data=(XPT2046_Data/100)%10;
//		LCD(2,Data);
//		Delay1();
//		Data=(XPT2046_Data/1000)%10;
//		LCD(1,Data);
//		Delay1();
	}
}

void TIMER_0_ISR()   interrupt 1
{
	TL0 = 0x00;		
	TH0 = 0xDC;	

		Data=XPT2046_Data%10;
		LCD(4,Data);
		Delay1();
		Data=(XPT2046_Data/10)%10;
		LCD(3,Data);
		Delay1();
		Data=(XPT2046_Data/100)%10;
		LCD(2,Data);
		Delay1();
		Data=(XPT2046_Data/1000)%10;
		LCD(1,Data);
		Delay1();
	
}	




