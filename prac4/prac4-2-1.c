#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int capacity = 4;   /* capacity of the array */
	int size = 0;       /* number of integers stored */
        int * array = (int *)malloc(capacity*sizeof(int));
        int k;
        scanf("%d", &k);
        while (k!=-1) 
	{
		if (size>=capacity) 
		{
			int *temparr = (int*)malloc(capacity*sizeof(int));
			capacity *= 2;
			
			temparr = &array[size+1];	
        	}
        	array[size++] = k;
            	scanf("%d", &k);
	}
        printf("The capacity of array is %d.\n", capacity);

	//for debugging
	/*for(int i =0; i< capacity; i++)
		printf("%d\n",array[i]);
	*/
}
