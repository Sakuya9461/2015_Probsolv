#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 26
#define MALLOC_STEP 10
#define WORD_MAX 50

char** table[TABLE_SIZE];
int capacity[TABLE_SIZE];
int size[TABLE_SIZE];


void init()
{
	//zeroize
	memset(capacity,0,TABLE_SIZE);
	memset(size,0,TABLE_SIZE);
}

int is_prefix(char * prefix, char * str) 
{
	if(!strncmp(prefix,str,strlen(prefix))) 
		return 1;
	else return 0;
}

void insert(char * word) 
{
	int index = word[0] - 'a';
	
	if (capacity[index] == 0) 
	{
		table[index] = (char**)malloc(sizeof(char**)*MALLOC_STEP);
		capacity[index] = MALLOC_STEP;
	}
	else if (capacity[index] <= size[index]) 
	{
		char* temp = (char*)malloc(sizeof(char*)*MALLOC_STEP);
		table[index+1] = &temp;
		capacity[index] += MALLOC_STEP;
	}
	table[index][size[index]] = (char*)malloc(sizeof(char*)*(strlen(word)+1));
	strncpy(table[index][size[index]],word,strlen(word));
	size[index]++;
}
int main(void) 
{
	FILE * fp = fopen("sample.txt", "r");
	init();
	char tmp[50];
	while (fscanf(fp, "%s", tmp) != EOF) 
		insert(tmp);
	
	fclose(fp);

	scanf("%s", tmp);
	int index = tmp[0] - 'a';
	for (int i = 0; i < size[index]; i++) 
	{
		char * str = *(table[index] + i);
		if (is_prefix(tmp, str))
			printf("%s\n", str);
	}

	return 0;
}
