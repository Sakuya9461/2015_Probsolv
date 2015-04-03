#include <stdio.h>

int main()
{
	int ret,a,cnt;
	ret = a =cnt = 0;
	while(1)
	{
		scanf("%d",&a);
		if(cnt++ % 2)
			ret += a;
		else
			ret -= a;
		if(!ret)
		{
			printf("%d",cnt);
			break;
		}
	}
}
