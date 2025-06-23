#include <stdio.h>
#include <stdlib.h>

//¼ÆËãnµÄ½×³Ë
int main()
{
  int a=0;
  int b=0;
  int ret=1;
  scanf("%d",&a);
  for(b=1;b<=a;b++)
  {
     ret =ret* b;
  }
printf ("%d",ret);
    return 0;
}


