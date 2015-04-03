#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int main()
{
	int dice;
	int N;
	char check = 0;
	srand(time(NULL));
	
	scanf("%d",&N);
	int dice1cnt=0;
	int dice2cnt=0;
	while(N--)
	{
		for(int i =0; i<6;i++)
		{
			dice = rand()%6+1;
			if(dice ==1)
			{
				dice1cnt++;
				break;
			}
		}
		for(int i =0; i<12; i++)
		{
			dice = rand()%6+1;
			if(dice ==1)
			{
				if(!check)
					check = 1;
				else
				{
					check = 0;
					dice2cnt++;
					break;
				}
			}
		}
	}
	printf("%d %d\n",dice1cnt,dice2cnt);
}

