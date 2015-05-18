#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4096

void sorting(char* string)
{
	int length = strlen(string);
        for(int i=0; i<length; i++)
        {
                for(int j=i; j<length; j++)
                {
                        //swap
                        if(string[i]>string[j])
                        {
                                char temp = string[i];
                                string[i] = string[j];
                                string[j] = temp;
                        }
                }
        }


}

int main()
{
	//for security reason..
	char* string1 = (char*)malloc(sizeof(char)*MAX);
	char* string2 = (char*)malloc(sizeof(char)*MAX);

	printf("First String  > ");
	scanf("%4095s",string1);	
	printf("Second String > ");
	scanf("%4095s",string2);

	sorting(string1);
	sorting(string2);

	if(strcmp((const char*)string1,(const char*)string2))
		printf("It is not anagram.\n");
	else
		printf("Two strings are anagram.\n");

}
