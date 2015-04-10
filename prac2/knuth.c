#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)  
{
	unsigned int N,M;
	int ** res = (int**)malloc(sizeof(int*)*N);
	int * perm = (int*)malloc(sizeof(int)*N);
	
	printf("N M >> ");
	scanf("%d %d",&N,&M);

	//2D array
	for(int i =0;i <N; i++)
	{
		res[i] = (int*)malloc(sizeof(int)*N);
		memset(res[i],0,sizeof(int)*N);
	}

	//seed init
	srand(time(NULL));

	while(M--)
	{
		printf("\n[*]CASE %d\n",M);
		//initialize

		for(int i =0; i <N; i++)
			perm[i] = i;
	
		//knuth
		for(int i =0; i <N; i++)
		{
			int r = i + (rand()%(N-i));
			int temp = perm[r];
			perm[r] = perm[i];
			perm[i] = temp;
			res[i][perm[i]] += 1;
			printf("%d ",perm[i]);
		}
	}

		printf("\n\n[*]Result\n");

		//print

		printf("    ");
		for(int i =0; i <N; i++)
			printf("%2d ",i);
		printf("\n   ");
		for(int i =0; i <N; i++)
			printf("---");
		printf("\n");
		for(int i =0; i <N; i++)
		{	printf("%2d |",i);
			for(int j =0;j  <N; j++)
				printf("%2d ",res[j][i]);
			printf("\n");
		}

		for(int i =0; i <N; i++)
			free(res[i]);
		free(res);
		free(perm);
}
