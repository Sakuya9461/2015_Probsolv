#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define bool char
#define START 0
#define END 1

void solve(int *array,int len)
{
	int history[2] ={0,};
	int max = 0;
	int cnt =1;
	bool isflat = 0;
	for(int i=0; i <len-1; i ++)
	{
		//is same~
		if(array[i] == array[i+1])
		{
			cnt++;

			//if isflat is false, it is not continuous in this time.
			if(!isflat)
			{
				//set flat and save index
				isflat = 1;
				history[START] = i;
			}
			history[END] = i+1;
		}
		else
		{
			isflat = 0;
			cnt = 1;
		}
		
		if(max<cnt)
			max = cnt;
	}
	printf("%d(%d,%d)\n",max,history[START],history[END]);
}


int main(int argc, char** argv)
{
	int array[MAX]={0,};
	int N;

	printf("N > ");
	scanf("%d",&N);
	
	for(int i =0; i<N ;i++)
		scanf("%d",&array[i]);

	//routine
	solve(array,N);
	
}	
