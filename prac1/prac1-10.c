#include <stdio.h>
int main()
{
	int a = 0;
	float ret = 0;
	scanf("%d",&a);
	for(int i =1; i<=a; i++)
	{
		if(i%2)
			ret += 4.0/(1+2*(i-1));	
		else
			ret -= 4.0/(1+2*(i-1));
		
	}
	printf("%f",ret);
}
