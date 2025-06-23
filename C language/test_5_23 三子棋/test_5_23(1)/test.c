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
	//初始化棋盘
	initialize_board(arr,Row,Col);
	//打印棋盘
	print_board(arr, Row, Col);
	while (1)
	{
		//玩家下棋
		player_board(arr, Row, Col);
		//判断是否获胜
		ret=is_win(arr, Row, Col);
		if (ret != 'm')
		{
			break;
		}
			
		print_board(arr, Row, Col);	

		//电脑下棋
		computure_board(arr, Row, Col);
		//判断是否获胜
		ret=is_win(arr, Row, Col);
		if (ret != 'm')
		{
			break;
		}
		print_board(arr, Row, Col);
		
	}

	if (ret == '*')
		printf("玩家获胜\n");
	else if (ret == '#')
		printf("电脑获胜\n");
	else
		printf("平局\n");
	print_board(arr, Row, Col);

}
int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		int a = 0;
		menu();
		printf("请输入：");
		scanf("%d", &a);
		if(a==1)
		{
			game();
		}
		else if (a==0)
		{
			printf("退出游戏\n");
			break;
		}	
		else
		{
			printf("选择错误，请重新选择！\n");
		}
		
	} 
	while (1);
		return 0;
}