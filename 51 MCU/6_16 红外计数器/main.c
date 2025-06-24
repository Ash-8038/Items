#include <REGX52.H>
#include <INT0.H>
#include <LCD1602.H>

unsigned char number;
unsigned char b;

void Delay100us()		//@11.0592MHz
{
	unsigned char i;
	i = 37;
	while (--i);
}


void main()
{
	INT0_INIT();
	LCD_Write_INIT();
	LCD_ShowString(1,1,"count:");
	while(1)
	{
		LCD_ShowNum(2,1,number,3);
		if(number>20)
		{
			for(b=0;b<100;b++)
			{
				LCD_ShowNum(2,1,number,3);
				P2_5=!P2_5;
				Delay100us();
			}
		}
	}
}

void INT0_ISR() interrupt 0
{
	while(P3_2==0);
	number++;
}