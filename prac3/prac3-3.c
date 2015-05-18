#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 50

void initialize_number_generator(void)
{
   srand((unsigned) time(NULL));
}

int play(int secret_number, int count)
{
	int guess, num_guesses = 0;
	while(1) 
	{
   		printf("Enter guess: ");
   		scanf("%d", &guess);
   		num_guesses++;
   		if (guess == secret_number) 
		{
      			printf("You won in %d guesses!\n\n", num_guesses);
			return num_guesses;
   		}
   	else if (guess < secret_number)
      		printf("Too low; try again.\n");
   	else
		printf("Too high; try again.\n");
	}
}

int choose_secret_number(void)
{
 	 int secret_number;
  	 secret_number = rand() % MAX_NUMBER + 1;
  	 return secret_number;
}

int main()
{
	char command;
	int secret_number;
	int count = -1;
	unsigned int min = -1;
	initialize_number_generator();
    	printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    	while(1)
    	{
        	secret_number = choose_secret_number();
        	count = play(secret_number,count);
        	printf("Play again? (Y/N) ");

        	//for clean buffer in Windows
		fflush(stdin);

		//for clean buffer in Linux
		fpurge(stdin);
		scanf("%c", &command);
        	if (command!='y' && command!='Y')
            		break;
		if(min>count)
		{
			printf("CONGRATURATION!! BEST SCORE!!\n");
			printf("BEST : %d\n",min);
			printf("YOU : %d\n",count);
			min = count;
		}
        	printf("\n");
	}
	return 0;
}
