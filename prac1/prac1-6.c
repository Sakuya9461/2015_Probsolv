#include <stdio.h>
int main()
{
	int ret = 0;
	for(int i =10; i<10000+1;i++)
	{
		int temp = i%100;
		if(temp%2 ==0 || temp%3 == 0)
			++ret;
	}

	printf ("%d\n",ret);
}
