#include <REGX52.H>

void Delay()		//@11.0592MHz 20ms
{
	unsigned char i, j;

	i = 36;
	j = 217;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char key()
{
	if(P3_1==0)
	{
		Delay();
		while(P3_1==0)
		Delay();
		return 1;
	}
	if(P3_0==0)
	{
		Delay();
		while(P3_0==0)
		Delay();
		return 2;
	}
	if(P3_2==0)
	{
		Delay();
		while(P3_2==0)
		Delay();
		return 3;
	}
	if(P3_3==0)
	{
		Delay();
		while(P3_3==0)
		Delay();
		return 4;
	}
	return 0;
}
