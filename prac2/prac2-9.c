#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define bool char

int* inverse(int *arr,int N)
{
	int *ret = (int*)malloc(sizeof(int)*N);

	for(int i =0; i<N; i++)
	{
		int idx =0;
		while(1)
		{
			if(arr[idx++] == i)
			{
				ret[i] =idx-1;
				break; 
			}
		}
		printf("%d ",ret[i]);
	}
printf("\n");
	return ret;
}

int* perm(int N)
{
	int *ret = (int*)malloc(N*sizeof(int));
	int *inv = (int*)malloc(N*sizeof(int));
	bool *isdup = (bool*)malloc(N);
	memset(isdup,0,N);
	int idx = 0;
	srand(time(NULL));
	//do not duplicate any number.
	while(idx<N)
	{
		int ran = rand()%N;
	
		if(!isdup[ran])
		{
			isdup[ran] = 1;
			ret[idx++] = ran;
		}
	}

	for(int i =0; i<N; i++)
		printf("%d ",ret[i]);
	printf("\n");
	return ret;
}


int main()
{
	int N;
	printf("N >> ");
	scanf("%d",&N);
	int* arr = perm(N);
	
	int* inv = inverse(arr,N);

	free(arr);
	free(inv);
}
