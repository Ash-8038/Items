#include <stdio.h>
#include <stdlib.h>
void mun()
 {
printf("**** 1,开始游戏 ********\n");
printf("**** 2,退出游戏 ********\n");
printf("************************\n");
printf("************************\n");
printf("************************\n");
 }
void game()
{

    int ret=rand()%100+1;//随机数变成0~100
    //printf("%d\n",ret);
    while(1)
    {
        int input =0;
    printf ("请输入：");
    scanf("%d",&input);
    if(input<ret)
    {
        printf ("太小了\n");

    }
    else if(input>ret)
    {
        printf ("太大了\n");
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
    srand ((unsigned int )time(NULL));//生成随机数
    int a=0;
    do
   {
     mun();
     printf ("请输入你的选择：");
     scanf ("%d",&a);
     switch(a)
     {
     case 1:
         //printf("猜数字:\n");
         game();
         break;
     case 2:
         printf("退出游戏\n");
         break;
     default :
         printf("输入错误\n");
         break;
     }
    }
    while(a!=2);
    return 0;
}
