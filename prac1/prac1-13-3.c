#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int main()
{
	char isPrime[MAX+1]={0,};
	
	//Prime Number is stared 2
	for(int i =2; i<=MAX; i++)
	{
		for(int j =2; j*i<=MAX; j++)
			isPrime[j*i]=1;
	}
	for(int i =2; i<=MAX; i++)
	{
		if(!isPrime[i])
			continue;
		else
			printf("%d\n",i);
	}
}
