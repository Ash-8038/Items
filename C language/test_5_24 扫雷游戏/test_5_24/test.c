#include"game.h"


menu()
{
	printf("*******1.  play    ***********\n");
	printf("*******0.  exit    ***********\n");
	printf("******************************\n");
}


void game()
{
	//������������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	Init_board(mine, ROWS, COLS,'0');
	Init_board(show, ROWS, COLS,'*');
	//����
	Make_boom(mine, ROW, COL);
	//��ӡ����
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);
	//����
	Play_board(mine,show, ROW, COL);

	

}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��");
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
			printf("�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("�����������ѡ��\n");
			break;
		}
		}
	} 
	while (input);
	return 0;
}