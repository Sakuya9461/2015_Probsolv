#include <stdio.h>
#include <stdlib.h>

#define BIG_NUMBER 2<<30

int main()
{
	int a[10]={0,};
	int min= (BIG_NUMBER) -1;
	int min2 = (BIG_NUMBER) -1;
	for(int i =0; i <10; i++)
		scanf("%d",&a[i]);
	
	//search
	for(int i =0; i<10; i++)
	{
		if(min > a[i])
			min = a[i];
	}
	
	for(int i =0; i <10; i++)
	{
		if(min2>=a[i])
			min2 = a[i];	
	}

	printf("MIN : %d MIN2 : %d\n",min,min2);
}
