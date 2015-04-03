#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 9

int main()
{
	int calc = 0;
	char* input = (char*)malloc(KEY_LENGTH);
	scanf("%s",input);

	for(int i=KEY_LENGTH-1; i>=0; i--)
		calc += (i+2)*(input[KEY_LENGTH+-1-i]-0x30);
	if(calc%11<=1){
		printf("x\n");
		return 0;
	}
	printf("%d\n",11 - calc%11);
}
