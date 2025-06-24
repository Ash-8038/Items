#include <REGX52.H>

sbit DQ=P3^7;

unsigned char ONE_WIRE_INIT()
{
	unsigned char i, ACK;
	DQ=1;
	DQ=0;
	i = 227;while (--i);	//—” ±500Œ¢√Î
	DQ=1;
	i = 32;while (--i);		//—” ±70Œ¢√Î
	ACK=DQ;
	i = 227;while (--i);	//—” ±500Œ¢√Î
	return ACK;
}

void ONE_WIRE_SEND(unsigned char BIT)
{
	unsigned char i;
	DQ=0;
	i = 3;while (--i);		//—” ±10Œ¢√Î
	DQ=BIT;
	i = 20;while (--i);	//—” ±50Œ¢√Î	
	DQ=1;
}

unsigned char ONE_WIRE_RECIVE()
{
	unsigned char i,BIT;
	DQ=0;
	i = 3;while (--i);		//—” ±10Œ¢√Î
	DQ=1;
	BIT=DQ;
	i = 20;while (--i);	//—” ±50Œ¢√Î	
	return BIT;
}

void ONE_WIRE_SEND_BYTE(unsigned char DATA)
{	
	unsigned char i;
	for(i=0;i<8;i++)
	{
		ONE_WIRE_SEND(DATA&=(0X01<<i));
	}
}

unsigned char ONE_WIRE_RECIVE_BYTE()
{
	unsigned char i,DATA=0X00;
	for(i=0;i<8;i++)
	{
		DATA|=ONE_WIRE_RECIVE();
		DATA<<=1;
	}
	return DATA;
}





























