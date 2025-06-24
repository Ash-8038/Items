#include <REGX52.H>

sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;
sbit LCD_EN=P2^7;

#define LCD_Data    P0

void Delay()		//@11.0592MHz1ms
{
	unsigned char i, j;
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void LCD_Write_Command(unsigned char Command)
{
	LCD_RS=0;
	LCD_WR=0;
	LCD_Data=Command;
	LCD_EN=1;
	Delay();
	LCD_EN=0;
	Delay();
}

void LCD_Write_Data(unsigned char Data)
{
	LCD_RS=1;
	LCD_WR=0;
	LCD_Data=Data;
	LCD_EN=1;
	Delay();
	LCD_EN=0;
	Delay();
}

void LCD_Write_INIT()
{
	LCD_Write_Command(0X38);
	LCD_Write_Command(0X0C);
	LCD_Write_Command(0X06);
	LCD_Write_Command(0X01);
}

void LCD_ShowChar(unsigned char line,unsigned char low,unsigned char Char)
{
	if(line==1)
	{
		LCD_Write_Command(0x80|(low-1));
	}
	else
	{
		LCD_Write_Command(0x80|(low-1)+0x40);
	}
	LCD_Write_Data(Char);
}

int LCD_POW(int x,int y)
{
	unsigned char i;
	int result=1;
	for(i=0;i<y;i++)
		{
			result*=x;
		}
	return result;
}
	//Ö»ÄÜÏÔÊ¾0~255£»
void LCD_ShowNum(unsigned char line,unsigned char low,unsigned char Num,unsigned char length)
{
	unsigned char i;
	if(line==1)
	{
		LCD_Write_Command(0x80|(low-1));
	}
	else
	{
		LCD_Write_Command(0x80|(low-1)+0x40);
	}
	for(i=length;i>0;i--)
	{
		LCD_Write_Data(Num/LCD_POW(10,i-1)%10+'0');
	}
}

void LCD_ShowString(unsigned char line,unsigned char low,unsigned char* String)
{
	unsigned char i;
	if(line==1)
	{
		LCD_Write_Command(0x80|(low-1));
	}
	else
	{
		LCD_Write_Command(0x80|(low-1)+0x40);
	}
	for(i=0;*(String+i)!='\0';i++)
	{
		LCD_Write_Data(*(String+i));
	}
}

void LCD_SHOWsignedNum(unsigned char line,unsigned char low,int Num,unsigned char length)
{
	unsigned char i;
	if(line==1)
	{
		LCD_Write_Command(0x80|(low-1));
	}
	else
	{
		LCD_Write_Command(0x80|(low-1)+0x40);
	}
	if(Num>=0)
	{
		LCD_Write_Data('+');
	}
	else
	{
		LCD_Write_Data('-');
		Num=-Num;
	}
	for(i=length;i>0;i--)
	{
		LCD_Write_Data(Num/LCD_POW(10,i-1)%10+'0');
	}

}








