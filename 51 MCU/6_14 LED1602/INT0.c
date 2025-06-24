#include <REGX52.H>
void INT0_INIT()
{
	IT0=1;
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;
}
	
//void INT0_ISR() interrupt 0
//{
//	
//}