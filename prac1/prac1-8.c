#include <stdio.h>
#include <math.h>

int main()
{
	int a, b,ret;
	ret =1;
	scanf("%d %d", &a, &b);
	for(int i =1; i<b+1;i++)
		ret *= a;
	printf("%d\n",ret);
}
