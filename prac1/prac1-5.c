#include <stdio.h>
int main(void)
{
	int a[5];
	scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	
	for(int i =0; i<5; i++)
	{
		for(int j=i+1; j <5 ;j++)
		{
			if(a[j]<a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	printf("%d\n",a[2]);	
	return 0;
}
