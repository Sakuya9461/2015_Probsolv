#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m(int* arr, int i, int j)
{
	if(i==j)
		return 0;
	else if(i<j)
	{
		for(int k = i; k<=j-1; k++)
			return (m(arr,i,k)+m(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
	}

	return 0;
}
int main()
{
	int* arr;
	int N;
	printf("N >> ");
	scanf("%d",&N);

	arr = (int*)malloc(sizeof(int)*N);
	for(int i =0; i <N; i++)
	{
		printf("%d >>",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("%d\n",m(arr,0,N-1));
}
