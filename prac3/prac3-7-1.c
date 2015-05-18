#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("[*]Usage : %s String\n",argv[0]);
		return 0;
	}

	int length = strlen(argv[1]);
	for(int i =length-1; i>=0 ; i--)
		printf("%c",argv[1][i]);
	printf("\n");
}
