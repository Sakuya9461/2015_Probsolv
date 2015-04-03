#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int main()
{
	int T,N;
	int c;
	scanf("%d %d",&T,&N);
	srand(time(NULL));	
	int x=0;
	int y=0;
	float sum = 0;
	int cnt =0;
	int total = N;
	while(N)	
	{
		c = rand()%4;
		switch(c)
		{	
			case UP:
				if(y<T)
				y++;
				break;
			case DOWN:
				if(y>-1*T)
				y--;
				break;
			case LEFT:
				if(x>-1*T)
				x--;
				break;
			case RIGHT:
				if(x<=T)
				x++;
				break;
			default:
				printf("error\n");
				break;
		
		}
		++cnt;

		if(abs(x) == T && y ==0 )
		{
			sum += cnt;
			N--;
			cnt =0;
			x=0;
			y=0;
		}
		if(abs(y) == T && x ==0 )
		{
			sum += cnt;
			cnt =0;
			N--;
			x=0;
			y=0;
		}
	}
	printf("AVER : %f\n",(sum/total));
}
