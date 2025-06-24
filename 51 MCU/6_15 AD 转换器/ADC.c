#include <REGX52.H>

sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

unsigned int XPT2046_READ(unsigned char command)
{
	unsigned char i=0;
	unsigned int Data=0;
	XPT2046_DCLK=0;
	XPT2046_CS=0;
	for(i=0;i<8;i++)
	{
		XPT2046_DIN=command&(0x80>>i);  //因为是上升沿输入，所以在上升沿来临之前就必须要将数据给到DIN。
		XPT2046_DCLK=1;
Delay1();			
		XPT2046_DCLK=0;
Delay1();	
	}
	for(i=0;i<16;i++)
	{
		XPT2046_DCLK=1;
Delay1();			//在下一个读的数据到来之前要给一个上升沿和一个下降沿，再输入数据（根据时序图）
		XPT2046_DCLK=0;
Delay1();	
		if(XPT2046_DOUT)
		{
			Data|=(0x8000>>i);
		}
	}
	XPT2046_CS=1;
Delay1();	
	return Data>>4;
}