#include <REGX52.H>
#include <INT0.H>
#include <TIMER0.H>

unsigned char IR_State;    //
unsigned int IR_Time;
unsigned char IR_Repeat_Flag;
unsigned char IR_Data_Flag;
unsigned char IR_Adderss;
unsigned char IR_Command;
unsigned char IR_Data[4];
unsigned char IR_P_Data;

void IR_INIT()
{
	void INT0_INIT();
	void TIMER0_INIT();
}

unsigned char IR_Data_Flag1()
{
	if(IR_Data_Flag)
	{
		IR_Data_Flag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_Repeat_Flag1()
{
	if(IR_Repeat_Flag)
	{
		IR_Repeat_Flag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAdderss()
{
	return IR_Adderss;
}

unsigned char IR_GetCommand()
{
	return IR_Command;
}

void INT0_ISR()			interrupt 0
{
	if(IR_State==0)
	{
		TIMER0_SetCounter(0);
		TIMER0_Run(1);
		IR_State=1;
	}
	else if(IR_State==1)
	{
		IR_Time=TIMER0_GetCounter();
		TIMER0_SetCounter(0);
		if(IR_Time>13500-500&&IR_Time<13500+500)
		{
			IR_State=2;
		}
		else if(IR_Time>11250-500&&IR_Time<11250+500)
		{
			IR_Repeat_Flag=1;
			TIMER0_Run(0);
			IR_State=0;	
		}
		else
		{
			IR_State=1;	
		}
	}
	else if(IR_State==2)
	{
		IR_Time=TIMER0_GetCounter();
		TIMER0_SetCounter(0);
		if(IR_Time>1120-500&&IR_Time<1120+500)
		{
			IR_Data[IR_P_Data/8]&=~(0x01<<(IR_P_Data%8));
			IR_P_Data++;
		}
		else if(IR_Time>2250-500&&IR_Time<2250+500)
		{
			IR_Data[IR_P_Data/8]&=~(0x01<<(IR_P_Data%8));
			IR_P_Data++;
		}
		else
		{
			IR_P_Data=0;
			IR_State=1;	
		}
	}
	if(IR_P_Data>=32)
	{
		IR_P_Data=0;
		if(IR_Data[0]==~IR_Data[1]&&IR_Data[2]==~IR_Data[3])
		{
			IR_Command=IR_Data[2];
			IR_Adderss=IR_Data[0];
			IR_Data_Flag=1;

		}
		TIMER0_Run(0);
		IR_State=0;
	}
	
	
	
	
}





















