#include"game.h"


menu()
{
	printf("*******1.  play    ***********\n");
	printf("*******0.  exit    ***********\n");
	printf("******************************\n");
}


void game()
{
	//设置两个数组
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	Init_board(mine, ROWS, COLS,'0');
	Init_board(show, ROWS, COLS,'*');
	//埋雷
	Make_boom(mine, ROW, COL);
	//打印数组
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);
	//排雷
	Play_board(mine,show, ROW, COL);

	

}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("输入错误，重新选择\n");
			break;
		}
		}
	} 
	while (input);
	return 0;
}