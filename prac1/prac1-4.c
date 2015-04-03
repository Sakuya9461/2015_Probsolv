#include <stdio.h>
int main(void)
{
 int a, b, c;
 int ta,tb,tc;
 scanf("%d %d %d", &a, &b, &c);

 ta = a+b-c>0;
 tb = b+c-a>0;
 tc = c+a-b>0;

 if(ta && tb && tc)
	printf("TRUE");
 else
	printf("FALSE");
 printf("\n");
 return 0;
}
