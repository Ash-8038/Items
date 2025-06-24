#include <REGX52.H>

sbit SCL=P2^1;
sbit SDA=P2^0;

void IIC_STAR()  //产生下降波形
{
	SDA=1;
	SCL=1;
	SDA=0;
	SCL=0;
}

void IIC_STOP()  //产生上升波形
{
	SDA=0;
	SCL=1;
	SDA=1;	
}

void IIC_SEND_BYTE(unsigned char DATA)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SDA=DATA&(0X80>>i);
		SCL=1;
		SCL=0;
	}
}

unsigned char IIC_RESIVE_BYTE()
{
	unsigned char DATA=0X00,i;
	SDA=1;
	for(i=0;i<8;i++)
	{
		SCL=1;
		if(SDA)
		{
			DATA|=(0X80>>i);
		}
		SCL=0;
	}
	return DATA;
}	
	
void IIC_SEND_ACK(unsigned char ACK)	
{
	SDA=ACK;
	SCL=1;
	SCL=0;
}
	
unsigned char IIC_RESIVE_ASK()	
{
	unsigned char ASK;
	SDA=1;
	SCL=1;
	ASK=SDA;
	SCL=0;
	return ASK;
}
	
	
	
	
	
	