#include <stdio.h>

int main()
{
	int ret=0;
	for(int i=10000; i<99999+1;i++)
	{
		int temp = i/1000;
		if(temp%3 == 0 || temp %7 ==0)
			++ret;
	}
	printf("%d\n",ret);
}
