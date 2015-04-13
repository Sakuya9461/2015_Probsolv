#include <stdio.h>
#include <stdlib.h>

#define E 0
#define W 1
#define S 2
#define N 3

int main()
{
	int d;
	int x,y;
	printf("d >> ");
	scanf("%d",&d);
	
	printf("input x,y >> ");
	scanf("%d,%d",&x,&y);
	
	switch(d)
	{
		case E:
			x++;
			break;
		case W:
			x--;
			break;
		case S:
			y--;
			break;
		case N:
			y++;
			break;
		default:
			printf("Error occur\n");
			exit(0);
			break;
	}
	printf("(%d,%d)\n",x,y);
}
