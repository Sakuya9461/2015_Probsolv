#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10.0

int main()
{
	float aver;
	float SD;
	float sum = 0;
	int arr[10];
	for(int i = 0 ; i <MAX ; i++)
	{
		scanf("%d",&arr[i]);
		aver += arr[i];
	}

	aver /= MAX;

	for(int i =0; i <MAX; i++)
	{
		int tmp = aver-arr[i];
		sum += tmp*tmp;
	}
	SD = sqrt(sum)/MAX;

	printf("AVER: %f, SD : %f\n",aver,SD);
}
