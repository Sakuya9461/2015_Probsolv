#include <stdio.h>
#include <string.h>

#define MAX_WORD 4000
#define MAX_LEN 20
#define MAX 4000

char dict[MAX_WORD][MAX_LEN];
char grid[MAX_LEN][MAX_LEN];
int n_words;
int LineOfGrid;

//too long
char get_char(int x, int y, int dir, int dist,int *px, int *py);
int search(int i);

void read_dictionary()
{
	FILE * fp = fopen("dict", "r");
	int i = 0;
	
	while (fscanf(fp, "%s", dict[n_words])!=EOF)
		n_words++;
}

void read_grid()
{
        FILE * fp = fopen("input-12.txt", "r");

        while (fscanf(fp, "%s", grid[LineOfGrid])!=EOF)
		LineOfGrid++;
}

int main()
{
	read_dictionary();
	read_grid();
	int i;
	for (i=0; i<n_words; i++) 
	{
		int result = search(i);
		if (result==1)
		printf("%s\n", dict[i]);
	}
	return 0;
}
int search(int idx)
{
	char* word = dict[idx];
	int word_len = strlen(word);
	int x;
	int y;

	for(int i =0; i<LineOfGrid; i++)
	{
		for(int j = 0; j <LineOfGrid; j++)
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
					return 1;
				}
			}
		}
	}

	return 0;
}

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
