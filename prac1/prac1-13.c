#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000

int cnt;

void decrease(char** num,int current)
{
	//end is 0
	if(!(*num)[current-1]){
		(*num)[current-1] = 0xa;
		if(current>0)
			decrease(num,current-1);
	}
	(*num)[current-1] -= 1;
}

int get_count(char* num,int len)
{
	int cnt = 0;
	while(1)
	{
		int sum = 0;
		for(int i =0; i<len; i++)
			sum += num[i];
		if(!sum)
			break;
		if(!(sum % 7))
			cnt++;
	
		decrease(&num,len);
			
	}
	return cnt;
}


int main()
{
	char* num = (char*)malloc(MAX);
	memset(num,0,sizeof(MAX));
	scanf("%s",num);

	int num_len = strlen(num);
	for(int i=0; i<num_len; i++)
		num[i] -=0x30;	
	printf("%d\n",get_count(num,num_len));
}
