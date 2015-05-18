#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 4096
int main()
{
	char *String = (char*)malloc(sizeof(char)*4096);
	scanf("%4095s",String);
	int length = strlen(String);

	for(int i=length; i>=0 ;i--)
		printf("%c",String[i]);
	printf("\n");
}
