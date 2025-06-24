#include<REGX52.H>
#include"delay.h"

int key()
{
	if(P3_1==0)
	{
		Delay1ms(20);while(P3_1==0);Delay1ms(20);return 1;
	}
	else
		return 0;
	
}