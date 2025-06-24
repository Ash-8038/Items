#include <REGX52.H>

void UART_INIT()
{
	PCON &= 0X7F;
	SCON = 0X50;	//9600bps@11.0592MHz
	TMOD &= 0x0F;		
	TMOD |= 0x20;
	TH1 = 0XFD;
	TL1 = 0XFD;
	TR1 = 1;
	ET1 = 0;
	ES = 1;
	EA = 1;
}

void UART_SEND(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}


void main()
{
	UART_INIT();
	while(1)
	{
		
	}
}

void UART_ISR() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		RI=0;
		UART_SEND(SBUF);
	}
}