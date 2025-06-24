#include<REGX52.H>

void Delay1ms(unsigned int x)		//@11.0592MHz
{
	unsigned char i, j;
  while(x--)
	{
  		j = 190;
			do
			{
				while (--j);
			} while (--i);
	}
}


void main()
{
	while(1)
	{
		if(P3_0==0)
		{
			Delay1ms(1);
			while(P3_0==0);
			Delay1ms(1);
			P2_0=~P2_0;	
		}
	}
}