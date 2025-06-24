#include <REGX52.H>

//void Delay1ms(unsigned char x)		//@11.0592MHz
//{
//	unsigned char i, j;
//	while(x--)
//	{
//			i = 11;
//		j = 190;
//		do
//		{
//			while (--j);
//		} while (--i);
//	}
//	
//}

void LCD(unsigned char x,unsigned char y)
{
	int arr[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	
		if(x==8)
		{
			P2_2=0;P2_3=0;P2_4=0;
		}
		if(x==7)
		{
			P2_2=1;P2_3=0;P2_4=0;
		}
		if(x==6)
		{
			P2_2=0;P2_3=1;P2_4=0;
		}
		if(x==5)
		{
			P2_2=1;P2_3=1;P2_4=0;
		}
		if(x==4)
		{
			P2_2=0;P2_3=0;P2_4=1;
		}
		if(x==3)
		{
			P2_2=1;P2_3=0;P2_4=1;
		}
		if(x==2)
		{
			P2_2=0;P2_3=1;P2_4=1;
		}
		if(x==1)
		{
			P2_2=1;P2_3=1;P2_4=1;
		}
		P0=arr[y];
	
	
}