#include <stdio.h>
#include <math.h>


void prob1(int a, int b, int c)
{
	double judge = pow(b,2)-4*a*c;
	if(judge<0)
	{
		printf ("NO ROOT\n");
		return ;
	}

	printf("%f %f",((-1*b)+sqrt(judge))/2*a,((-1*b)-sqrt(judge))/2*a);
	printf("\n");
}

void prob2()
{
	for(int i=0 ; i<100+1; i+=10)
		printf("%f\n",i*1.8+32);
}

int main(int argc, char** argv)
{
	int a,b,c;
	printf("prob1-----\n");
	scanf("%d %d %d",&a,&b,&c);
	prob1(a,b,c);
	printf("prob2-----\n");
	prob2();
}
