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
		XPT2046_DIN=command&(0x80>>i);  //��Ϊ�����������룬����������������֮ǰ�ͱ���Ҫ�����ݸ���DIN��
		XPT2046_DCLK=1;
Delay1();			
		XPT2046_DCLK=0;
Delay1();	
	}
	for(i=0;i<16;i++)
	{
		XPT2046_DCLK=1;
Delay1();			//����һ���������ݵ���֮ǰҪ��һ�������غ�һ���½��أ����������ݣ�����ʱ��ͼ��
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