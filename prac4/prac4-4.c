#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 40
#define INPUT "text.txt"
#define OUTPUT "./words.txt"
#define MAXCOUNT 4000 
#define bool char

int nwords;
char* word[MAXCOUNT];

void read_dictionary()
{
        FILE* f = fopen(INPUT,"r");
        int i =0;
	char temp[MAXLEN+1];
        while(!feof(f))
        {
		fgets(temp,MAXLEN,f);

		// string + new line character
		if(strlen(temp)>=4+1)
		{
			bool dup = 0;
			
			//delete new line character
			temp[strlen(temp)-1] = '\x00';
			
			for(int idx =0; idx <i; idx++)
			{
				if(!strcmp(temp,word[idx]))
					dup = 1;
			}
			if(!dup)
                	{
				word[i] = (char*)malloc(MAXLEN+1);
                		strncpy(word[i++],temp,strlen(temp));
			}
		}
	}
        nwords = i;
	fclose(f);
}

void swap(char** arg1, char** arg2)
{
	char* temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

void sorting()
{
	for(int i =0; i <nwords; i++)
	{
		for(int j = i; j <nwords; j++)
		{
			if(strcmp(word[i],word[j])>0)
				swap(&word[i],&word[j]);
		}
	}
}

void write_file()
{
	FILE *f = fopen(OUTPUT,"w");
	
	for(int i=0; i <nwords; i++)
	{
		fwrite(word[i],1,strlen(word[i]),f);
	
		//insert new line
		fwrite("\r\n",1,2,f);
	}
	fclose(f);
}
void print_result()
{
	for(int i =0; i <nwords; i++)
		printf("%d : %s\n",i,word[i]);
}

int main()
{
	read_dictionary();
	sorting();
	print_result();
	write_file();
}
