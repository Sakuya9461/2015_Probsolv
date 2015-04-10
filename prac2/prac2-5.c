#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solve(int *arr, int N)
{
	int wall = -1;
	int cnt = 1;

	for(int i =0; i <N; i++)
	{
		if(arr[i]>=wall)
			wall= arr[i];
		else
			cnt++;
	}
	printf("%d", cnt);
}

int main()
{
	int N;
	printf("N >> ");
	scanf("%d",&N);

	int *arr = (int*)malloc(sizeof(int)*N);
	memset(arr,0,sizeof(int)*N);

	for(int i =0; i<N ; i++)
	{
		printf("%d >> ",i+1);
		scanf("%d",&arr[i]);
	}

	solve(arr,N);
}
