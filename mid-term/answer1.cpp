#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 1000
int main()
{
	int cnt = 0;
	for (int a = 1; a < LINE; a++)
	{
		for (int b = a; b < LINE; b++)
		{
			int c = b*b + a*a;
			if (c <= 1000)
				cnt++;
			else
				break;
		}
	}
	printf("%d", cnt);
}