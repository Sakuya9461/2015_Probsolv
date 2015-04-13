#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
	int arr[MAX];

	//input
	for(int i =0; i <MAX; i++)
		scanf("%d",&arr[i]);
	
	//last value save in other var.
	int temp = arr[MAX-1];

	//pull back all value in array	
	for(int i=MAX-1; i>0; i--)
		arr[i] = arr[i-1];

	//push value in array's first index
	arr[0] = temp;

	//print
	for(int i =0; i <MAX; i++)
		printf("%d ",arr[i]);
}
