#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma warning(disable:4996)
int main()
{
	int N;
	int *arr = NULL;
	scanf("%d", &N);
	
	//배열선언
	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	//최소, 최대값 선언
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < N; i++)
	{
		if (min>arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d", max - min);
	
}