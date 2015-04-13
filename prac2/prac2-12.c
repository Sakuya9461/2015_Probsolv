#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int N,K;
	int cnt =0;
	int *array;
	
	//input
	printf("N >> ");
	scanf("%d",&N);
	array = (int*)malloc(sizeof(int)*N);

	for(int i=0; i <N; i++)
	{
		printf("%d >> ",i+1);
		scanf("%d",&array[i]);
	}

	printf("K >> ");
	scanf("%d",&K);
	
	for(int i =0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(array[i]+array[j] == K)
				cnt++;
		}
	}

	printf("%d\n",cnt);
	free(array);
}
