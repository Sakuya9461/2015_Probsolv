#include <stdio.h>

int main()
{
	int x,y,cnt;
	cnt = 0;
	for(x=0;x<100;x++)
	{
		for(y=0;y<100;y++)
		{
			if(x*x + y*y <=100*100)
				cnt++;	
		}
	}		
	printf("%d\n",cnt);
}
