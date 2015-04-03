#include <stdio.h>
#include <math.h>

int main()
{
	for(int i =2; i<=100000; i++)
	{
		int isprime = 1;
		//for(int j=2; j<= i/2 && isprime==1 ; j++)
		for(int j=2; j*j<=i; j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}
		}
		if(isprime==1)
			printf("%d\n",i);
	}
	return 0;
}
