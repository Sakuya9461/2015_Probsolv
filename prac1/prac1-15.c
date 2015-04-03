#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
	int N;
	int idx=0;
	int array_length;
	int x3;
	int y3;
	int diff_cnt =0;
	int array[(MAX+1)*(MAX+1)]={0,};
	int cnt = 0;
	
	scanf("%d",&N);
	//make list
	for(int y =1; y <=MAX; y++)
	{
		for(int x=y; x<=MAX; x++)
		{
			x3 = x*x*x;
			y3 = y*y*y;
			if(x3 + y3>N)
				break;
			else
				array[idx++] = x3+y3;
		}
	}

	array_length = idx;
	idx = 0;

	for(int j =0; j<array_length ; j++)
	{
		for(int i =0; i <=array_length; i++)
		{
			if( i!=j && array[j] == array[i])
			{
				printf("%d\n",array[j]);
				array[i]=i;
			}
		}
	}

}

