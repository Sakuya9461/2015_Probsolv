#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pi(int N)
{
	double ret=0;
	int sign = 1;
	for(int i =1; i <N; i+=2)
	{
		ret += (double)sign/i;
		sign *=-1;
	}

	ret *=4;
	return ret;
}

int main()
{
	double p =0;
	int N;
	printf("N >> ");
	scanf("%d",&N);
	printf("%f\n",pi(N));
}
