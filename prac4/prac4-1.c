#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int n, int *arr)
{
	for(int i =0; i<n; i++)
	{
		for(int j =i; j<n ;j++)
		{
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
		}
	}
}

int main()
{
	int arr[MAX]={0,};
	for(int i =0; i <MAX; i++)
	{
		printf("%d >> ",i+1);
		scanf("%d",&arr[i]);
	}
	bubble(MAX,arr);

	for(int i =0; i<MAX; i++)
	printf("%d\n",arr[i]);
}
