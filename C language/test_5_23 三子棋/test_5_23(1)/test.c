#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("********1. play**********\n");
	printf("********0. exit**********\n");
	printf("*************************\n");
}
void game()
{
	char ret = 0;
	char arr[Row][Col] = { 0 };
	//��ʼ������
	initialize_board(arr,Row,Col);
	//��ӡ����
	print_board(arr, Row, Col);
	while (1)
	{
		//�������
		player_board(arr, Row, Col);
		//�ж��Ƿ��ʤ
		ret=is_win(arr, Row, Col);
		if (ret != 'm')
		{
			break;
		}
			
		print_board(arr, Row, Col);	

		//��������
		computure_board(arr, Row, Col);
		//�ж��Ƿ��ʤ
		ret=is_win(arr, Row, Col);
		if (ret != 'm')
		{
			break;
		}
		print_board(arr, Row, Col);
		
	}

	if (ret == '*')
		printf("��һ�ʤ\n");
	else if (ret == '#')
		printf("���Ի�ʤ\n");
	else
		printf("ƽ��\n");
	print_board(arr, Row, Col);

}
int main()
{
	srand((unsigned int)time(NULL));//������������������
	do
	{
		int a = 0;
		menu();
		printf("�����룺");
		scanf("%d", &a);
		if(a==1)
		{
			game();
		}
		else if (a==0)
		{
			printf("�˳���Ϸ\n");
			break;
		}	
		else
		{
			printf("ѡ�����������ѡ��\n");
		}
		
	} 
	while (1);
		return 0;
}