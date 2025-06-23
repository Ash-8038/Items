#include"game.h"

//初始化数组
void Init_board(char board[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印数组
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("****扫雷游戏*****\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("*****************\n");

}

//埋雷
void Make_boom(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int c4 = 0;
	
	while (c4<boom)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			c4++;
		}	
	}
}


int get_board(char board[ROWS][COLS],int x,int y)
{
	return ( board[x - 1][y - 1] + board[x - 1][y]
		+ board[x - 1][y + 1] + board[x][y - 1]
		+ board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]- 8 * '0');

	



}
//排雷
void Play_board(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int blank = 0;
	
	while (blank<=ROW*COL-boom)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&& y >= 1 && y  <= col)
		{

			if (mine[x][y] == '1')
			{
				printf("很遗憾 BOOM\n");
				Display_board(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_board(mine, x, y);
				show[x][y] = count+'0';
				Display_board(show, ROW, COL);
				blank++;
				
			}
				
		}
		else
			printf("输入坐标错误\n");

	}
	if(blank > ROW * COL - boom)
	printf("恭喜获胜\n");

}