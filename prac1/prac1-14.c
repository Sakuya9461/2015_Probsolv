#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isprime(int x, int y)
{
	int cnt = 0;
	int temp;
	if(x>y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	for(int i =1; i<=y; i++)
	{
		if(x%i ==0 && y%i ==0)
			 cnt++;
	}
	if(cnt >1)
		return ' ';
	else
		return '*';
}

int main()
{
	int table_size;
	scanf("%d",&table_size);
	char* arr = (char*)malloc(table_size*table_size);
	memset(arr,0,table_size*table_size);

	//print matrix
	for(int i = 0 ; i<=table_size-1;i++)
		printf("    %d\t",i+1);
	printf("\n+");
	for(int i = 0; i<=table_size-1;i++)
		printf("-------+");
	printf("\n");

	//calc
	for(int y=1; y <=table_size; y++)
	{
		for(int x=1; x <=table_size; x++)
		{
			printf("|   %c\t",isprime(x,y));
		}
		printf("|%d\n",y);
		printf("+");
		for(int i=0; i<table_size;i++)
			printf("-------+");
		printf("\n");
	}

	//end
}
