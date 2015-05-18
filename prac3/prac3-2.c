#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this is euclidean algorithm.
int get_gcd(int a, int b)
{
	//swap for sorting
	if(b>a)
	{
		int temp = b;
		b = a;
		a = temp;
	}

	if(b ==0)
		return a;

	if(b%a == 0)
		return b;
	else
	{
		int a1 = a%b;
		return get_gcd(b,a1);
	}
}

int main()
{
	int m,n;
	printf("INPUT TWO NUMBER >> :");
	scanf("%d %d",&m,&n);
	printf("%d\n",get_gcd(m,n));
}
