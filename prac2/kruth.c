#include <stdio.h>
#define MAX 100
int main() 
{
	int perm[MAX];
	int M, N;
	scanf("%d %d", &N, &M);
	
	for (int j = 0; j < N; j++)
        	perm[j] = j;
	
	for(inti=0;i<M;i++) 
	{ 
		int r = i + (rand()%(N-i));
		int t = perm[r];  
		perm[r] = perm[i];  
		perm[i] = t;
	}

	for (int i = 0; i < M; i++)
		print(perm[i]);
}
