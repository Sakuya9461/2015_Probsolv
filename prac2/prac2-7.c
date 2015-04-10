#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int N ;
	printf("N >> ");
	scanf("%d",&N);
	int *arr =(int*)malloc(sizeof(int)*N);
	memset(arr,-1,sizeof(int)*N);
	
	for(int i =0; i<N; i++)
	{
		int temp;
		printf("%d >>",i+1);
		scanf("%d",&temp);
		for(int j = 0; j<N; j++)
		{
			if(arr[j] == temp)
			{
				printf("YES\n");
				exit(0);
			}
		}
		arr[i] = temp;	
	}
	printf("NO\n");
}
