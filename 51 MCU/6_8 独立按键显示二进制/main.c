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
	int i=0;
	
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(1);
			while(P3_1==0);
			Delay1ms(1);
		  i++;
			P2=~i;
			
		}
	}
	
}


