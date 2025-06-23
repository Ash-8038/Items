#include"game.h"



void initialize_board(char arr[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}

	}
}

void print_board(char arr[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			if (j == Col - 1)
			{
				printf(" %c ", arr[i][j]);
				break;
			}
			printf(" %c ", arr[i][j]);
			printf("|");
		}
		printf("\n");
		if (i < Row - 1)
		{
			for (j = 0; j < Col; j++)
			{
				if (j == Col - 1)
				{
					printf("---\n");
					break;
				}
				printf("---|");
		}
		}	
	}
}


void player_board(char arr[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("玩家下棋\n");
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= Row && y >= 1 && y <= Col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("此格子不能下子\n");
		}
		else
			printf("坐标输入错误，请重新选择\n");

	}
}



void computure_board(char arr[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋\n");
	while (1)
	{
		
		x = rand() % Row;
		y = rand() % Col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}

}

//int is_full(char arr[Row][Col], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < Row; i++)
//	{
//		for (j = 0; j < Col; j++)
//		{
//			if (arr[i][j] == ' ')
//				return 0;
//
//		}
//
//
//	}
//	return 1;
//
//}


char is_win(char arr[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	//横着的数
	for (i = 0; i < Row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];

		}
	}

	//竖着的数
	for (j = 0; j < Col; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return arr[0][j];

		}
	}
	//斜着的数
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	{
		return arr[0][0];
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}


	//if (is_full(arr, row, col))
	//{
	//	return 'c';

	//}
	//else
	//	return 'm';

	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			if (arr[i][j] == ' ')
				return 'm';

		}
	}

	return 'c';
}