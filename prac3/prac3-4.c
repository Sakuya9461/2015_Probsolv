#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COUNT 1000
#define bool char
#define false 0
#define true 1 

int get_value(int* data, int a, int b)
{
	int ret =0;
	int by = 0;
	for(int i =b; i>=a; i--)
		ret += data[i]*pow(10.0,by++);
	return ret;
}

bool is_dup(int *primes, int value)
{
	int i=0;
	while(primes[i])
	{
		if(value == primes[i++])
			return true;
	}
		return false;
}

int add(int n, int* primes, int k)
{
	if(!is_dup(primes,k))
	{
		primes[n++] = k;
		printf("PRIME[%d] = %d\n",n,k);
	}
	return n;
}

bool is_prime(int value)
{
	for(int i=2; i<value; i++)
	{
		if(!(value%i))
			return false;
	}
	return true;
}

int main()
{
	int input_length = 0;
	int is_over =0;
	int prime_count =0;
	int value;
	
	int* arr = (int*)malloc(sizeof(int)*MAX_COUNT);
	memset(arr,0,sizeof(int)*MAX_COUNT);

	int *prime_arr = (int*)malloc(sizeof(int)*MAX_COUNT);
	while(1)
	{
		is_over = scanf("%d",&arr[input_length++]);
		if(is_over == EOF)
			break;
	}
	//becuz input_length++
	input_length--;
	
	//divide and find prime
	for(int i=0; i<input_length; i++)
	{
		for(int j=i;j<8;j++)
		{
			//prime_count MAX is 1000
			if(prime_count >MAX_COUNT)
			{
				printf("1000\n");
				return 0;
			}
			
			//out of range
			if((i+j)>=input_length)
			{
				value = get_value(arr,i,input_length-1);
				if(is_prime(value))
					prime_count = add(prime_count, prime_arr, value);
				break;
			}
			
			//else case	
			value = get_value(arr,i,i+j);
			if(is_prime(value))
				prime_count = add(prime_count,prime_arr,value);
		}
	}
	printf("COUNT : %d\n",prime_count);
}
