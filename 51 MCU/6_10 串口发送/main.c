#include <REGX52.H>

void UART_INIT()
{
	PCON &= 0X7F;
	SCON = 0X40;	//9600bps@11.0592MHz
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	ET1 = 0;
	TR1 = 1;
	TH1 = 0XFD;
	TL1 = 0XFD;
}

void UART_send(unsigned char x)
{
	SBUF=x;
		while(TI==0);
		TI=0;
}



void main()
{
	UART_INIT();
	UART_send(0X54);
	while(1)
	{
		
	}
}
