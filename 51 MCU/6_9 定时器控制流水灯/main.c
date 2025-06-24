#include "key.h"
#include <INTRINS.H>
void Timer0_Init()
{
	TMOD=0X01; 		//设置定时器工作方式
	TR0=1;			//允许定时器0工作
	TF0=0;			//中断溢出标志位置0
	TL0=64535%256;	//设置处置低八位
	TH0=64535/256;	//设置初值高八位
	EA=1;			//中断总允许位
	ET0=1;			//T0定时器终端开关
	PT0=0; 			//T0定时器中断优先级设置为默认低优先级
}
unsigned char keynum,mode;
void main()
{
	P2=0XFE;
	Timer0_Init();
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			mode++;
			if(mode>=2)mode=0;
		}
		
			
	}	
}

void Timer0_IRS() interrupt 1
{
	static int count=0;		//修饰count变量
	TL0=64535%256;
	TH0=64535/256;
	count++;
	if(count>500)
	{
		count=0;
		if(mode==0)
		{
			P2=_cror_(P2,1);
		}
		if(mode==1)
		{
			P2=_crol_(P2,1);
		}
	}
}