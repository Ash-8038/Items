#include<REGX52.h>

void Delay1ms(unsigned int x)		//@11.0592MHz
{
		while(x--)
		{
				unsigned char i, j;
				i = 11;
				j = 190;
				do
				{
					while (--j);
				} while (--i);
			
		}
}

void main()
{
		int i=0x01;
	while(1)
	{
		P2=~i;
		i<<=1;
		if(i>0x80)
		{
			i=0x01;
		}
		Delay1ms(50);
	}
}
	