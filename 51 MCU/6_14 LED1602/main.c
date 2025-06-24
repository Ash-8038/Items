#include <REGX52.H>
#include <IR.H>
#include <LCD1602.H>

unsigned char ADRESS1;
unsigned char NUMBER1;

void main()
{
	LCD_Write_INIT();
	IR_INIT();
	while(1)
	{
		LCD_ShowString(1,1,"adre");

		
		if(IR_Repeat_Flag1())
		{
			ADRESS1=IR_GetCommand();
			LCD_ShowNum(2,1,ADRESS1,4);
			if(ADRESS1==0X15)
			{
				NUMBER1--;
			}
			if(ADRESS1==0X09)
			{
				NUMBER1++;
			}
			LCD_ShowNum(2,9,NUMBER1,4);
		}
	}
}


