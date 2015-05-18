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
	char* string = (char*)malloc(sizeof(char)*MAX);
	scanf("%4095s",string);	

	sorting(string);

	printf("%s\n",string);
}
