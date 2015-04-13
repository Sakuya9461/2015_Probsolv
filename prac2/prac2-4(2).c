#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
	int arr[MAX];
	for(int i =0; i <MAX; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int temp = arr[MAX-1];

	for(int i=MAX-1; i>0; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[0] = temp;

	for(int i =0; i <MAX; i++)
		printf("%d ",arr[i]);
}
