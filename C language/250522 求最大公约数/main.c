#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    int b=0;
    scanf("%d %d",&a,&b);
    int min=(a<b)?a:b;
    int m=min;
while(1)
{

    if(a%m==0&&b%m==0)
       {
         break;
       }
    else
       m--;
}
printf("%d",m);









    return 0;
}
