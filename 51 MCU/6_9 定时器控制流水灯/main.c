#include "key.h"
#include <INTRINS.H>
void Timer0_Init()
{
	TMOD=0X01; 		//���ö�ʱ��������ʽ
	TR0=1;			//����ʱ��0����
	TF0=0;			//�ж������־λ��0
	TL0=64535%256;	//���ô��õͰ�λ
	TH0=64535/256;	//���ó�ֵ�߰�λ
	EA=1;			//�ж�������λ
	ET0=1;			//T0��ʱ���ն˿���
	PT0=0; 			//T0��ʱ���ж����ȼ�����ΪĬ�ϵ����ȼ�
}
unsigned char keynum,mode;
void main()
{
	P2=0XFE;
	Timer0_Init();
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			mode++;
			if(mode>=2)mode=0;
		}
		
			
	}	
}

void Timer0_IRS() interrupt 1
{
	static int count=0;		//����count����
	TL0=64535%256;
	TH0=64535/256;
	count++;
	if(count>500)
	{
		count=0;
		if(mode==0)
		{
			P2=_cror_(P2,1);
		}
		if(mode==1)
		{
			P2=_crol_(P2,1);
		}
	}
}