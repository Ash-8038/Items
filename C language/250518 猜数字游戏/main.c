#include <stdio.h>
#include <stdlib.h>
void mun()
 {
printf("**** 1,��ʼ��Ϸ ********\n");
printf("**** 2,�˳���Ϸ ********\n");
printf("************************\n");
printf("************************\n");
printf("************************\n");
 }
void game()
{

    int ret=rand()%100+1;//��������0~100
    //printf("%d\n",ret);
    while(1)
    {
        int input =0;
    printf ("�����룺");
    scanf("%d",&input);
    if(input<ret)
    {
        printf ("̫С��\n");

    }
    else if(input>ret)
    {
        printf ("̫����\n");
    }
    else
        {
        printf ("right\n");
        break;
        }
    }

}



int main()
{
    srand ((unsigned int )time(NULL));//���������
    int a=0;
    do
   {
     mun();
     printf ("���������ѡ��");
     scanf ("%d",&a);
     switch(a)
     {
     case 1:
         //printf("������:\n");
         game();
         break;
     case 2:
         printf("�˳���Ϸ\n");
         break;
     default :
         printf("�������\n");
         break;
     }
    }
    while(a!=2);
    return 0;
}
