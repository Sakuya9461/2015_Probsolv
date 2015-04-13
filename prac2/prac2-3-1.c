#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *x;
	int *y;
	int EWSN[4] = {1,-1,-1,1};
	int d;
	int dist;

	//input
	printf("input 0-3 : ");
	scanf("%d",&d);

	printf("x : ");
	x = (int*)malloc(sizeof(int));
	scanf("%d",x);

	printf("y : ");
	y = (int*)malloc(sizeof(int));
	scanf("%d",y);

	//distance in memory	
	dist = y-x;

	//write on memory
	x = (int*)(x+dist*(d/2));
	*x += EWSN[d];
	x = (int*)(x-dist*(d/2));
	
	//print
	printf("(%d,%d)\n",*x,*y);
}
