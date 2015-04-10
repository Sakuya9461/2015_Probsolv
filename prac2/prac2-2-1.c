#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *x;
	int *y;
	int EWSN[4] = {1,-1,-1,1};
	int d;
	int dist;
	printf("input 0-3 : ");
	scanf("%d",&d);

	printf("x : ");
	x = (int*)malloc(sizeof(int));
	scanf("%d",x);

	printf("y : ");
	y = (int*)malloc(sizeof(int));
	scanf("%d",y);
	
	dist = y-x;

	x = (int*)(x+dist*(d/2));
	*x += EWSN[d];
	x = (int*)(x-dist*(d/2));
	
	printf("(%d,%d)\n",*x,*y);
}
