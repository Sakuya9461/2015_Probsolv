#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int is_cancle;
	int array[MAX]={0,};
	int len = 0;
	
	//input
	for(len =0; len<MAX; len++)
	{
		printf("%d >> ",len+1);
		is_cancle = scanf("%d",&array[len]);

		if(is_cancle == EOF)
			break;
	}
	
	//sort
	for(int i=0; i <len; i++)
	{
		for(int j=i; j<len ; j++)
		{
			if(array[i]>array[j])
			{
				//swap
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	//delete number	
	int temp;
	printf(" INPUT >> ");
	scanf("%d",&temp);

	//search and delete
	for(int i =0; i <len-1 ; i++)
	{
		if(temp == array[i])
		{
			for(int j=i ; j<len;j++)
				array[j] = array[j+1];
		}
		printf("%d ",array[i]);
	}
	printf("\n");
	
}
