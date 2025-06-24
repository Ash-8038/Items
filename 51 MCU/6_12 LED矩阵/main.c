#include <REGX52.H>
#include <LED.H>

void Delay1ms(unsigned char i)			//@11.0592MHz
{
	

	i = 43;
	while (--i);
}



void main()
{
	P3_5=0;
	P3_6=0;
	while(1)
	{
		LED(0,0X7E);
		Delay1ms(1);
		LED(1,0X81);
		Delay1ms(1);
		LED(2,0X95);
		Delay1ms(1);
		LED(3,0XA1);
		Delay1ms(1);
		LED(4,0XA1);		
		Delay1ms(1);
		LED(5,0X95);
		Delay1ms(1);
		LED(6,0X81);
		Delay1ms(1);
		LED(7,0X7E);
		Delay1ms(1);

	}
}
