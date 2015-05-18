#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char grid[MAX][MAX];
int N;
char word[MAX];
int word_len;

/*DEFINE DIRECTION

1	2	3

4		5

6	7	8

*/

char get_char(int x, int y, int dir, int dist,int *px, int *py)
{
	switch(dir)
	{
		case 1:
			if(x-dist>=0 && y-dist>=0)
			{
				*px = x-dist;
				*py = y-dist;
				return grid[x-dist][y-dist];
			}
			break;
		case 2:
			if(y-dist>0)
			{
                                *px = x;
                                *py = y-dist;
				return grid[x][y-dist];
			}
			break;
		case 3:
			if(x+dist<MAX && y-dist>=0)
			{
                                *px = x+dist;
                                *py = y-dist;
				return grid[x+dist][y-dist];
			}	
			break;
		case 4:
			if(x-dist>=0)
			{
                                *px = x-dist;
                                *py = y;
				return grid[x-dist][y];
			}	
			break;
		case 5:
			if(x+dist<MAX)
			{
                                *px = x+dist;
                                *py = y;
				return grid[x+dist][y];
			}	
			break;
		case 6:
			if(x-dist>=0 && y+dist<MAX)
			{
                                *px = x-dist;
                                *py = y+dist;
				return grid[x-dist][y+dist];
			}
				break;
		case 7:
			if(y+dist<MAX)
			{
                                *px = x;
                                *py = y+dist;
				return grid[x][y+dist];
			}
				break;
		case 8:
			if(x+dist<MAX && y+dist<MAX)
			{
                                *px = x+dist;
                                *py = y+dist;
				return grid[x+dist][y+dist];
			}
			break;
	}
	return 0;
}

int main()
{
	FILE * fp = fopen("input.txt","r");
	fscanf(fp,"%d",&N);
	for(int i =0; i <N ; i++)
		fscanf(fp,"%s",grid[i]);
	fclose(fp);

	scanf("%s",word);
	word_len = strlen(word);

	int x;
	int y;

	for(int i =0; i<N; i++)
	{
		for(int j = 0; j <N; j++)
		{
			if(grid[i][j] != word[0])
				continue;
			for(int dir = 0; dir<8; dir++)
			{
				//dist 1=>0;
				int dist =0;
				for(; dist<word_len; dist++)
				{
					char ch = get_char(i,j,dir,dist,&x,&y);
					if(!ch || ch != word[dist])
						break;
				}
				
				//is correct
				if(dist >= word_len)
				{
					dist = 0;
					for(; dist<word_len; dist++)
					{
						char ch = get_char(i,j,dir,dist,&x,&y)^0x20;
						grid[x][y] = ch;
					}
				}
			}
		}
	}

	for(int i =0; i<N;i++)
		printf("%s\n",grid[i]);
	return 0;
}
