#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
        int is_cancle;
        int array[MAX]={0,};
        int len = 0;
	int cnt = 0;

        //input
        for(len =0; len<MAX; len++)
        {
                printf("%d >> ",len+1);
                is_cancle = scanf("%d",&array[len]);

                if(is_cancle == EOF)
                        break;
        }	

	//routine
	for(int i=1; i<len-1; i++)
	{
		if(array[i-1] <= array[i] && array[i] >=array[i+1])
			cnt++;
	}

	printf("%d\n",cnt);

}
