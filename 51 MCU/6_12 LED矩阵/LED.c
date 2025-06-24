#include <REGX52.H>

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
void Delay1ms( )			//@11.0592MHz
{
	unsigned char i;

	i = 43;
	while (--i);
}

void _74HC95(unsigned char COL)
{
	char i=8;
	char num=0;
	while(i--)
	{
		SER=COL&(0X01<<num);
		SCK=1;
		SCK=0;
		num++;
	}
	RCK=1;
	RCK=0;
}
//ROW 表示第几列范围0~7 DATA 代表第几行
void LED(unsigned char ROW,DATA)
{
	_74HC95(DATA);
	P0=~(0X80>>ROW);
	Delay1ms( );
	P0=0XFF;
	
}

