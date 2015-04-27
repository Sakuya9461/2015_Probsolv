#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)
int main()
{
	int N;
	int K;
	
	scanf("%d %d", &N, &K);
	printf("%d", N&(int)pow(2.0, K));

}