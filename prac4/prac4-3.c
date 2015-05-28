#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAXWORDS 4000
#define MAXLEN 40
#define LIMIT 20

#define PATH "dict"
#define bool char


char* word[MAXWORDS];
int nwords;
int index_chosen_word;


//set random seed by TIMESTAMP 
void initialize_number_generator()
{
	srand(time(NULL));
}


//Read dict. file and save data in array.
void read_dictionary()
{
	FILE* f = fopen(PATH,"r");	
	int i =0;
	while(!feof(f))
	{
		word[i] = (char*)malloc(MAXLEN+1);
		fgets(word[i++],MAXLEN,f);
	}
	nwords = i;
}

//random word selection
void choose_word()
{
	index_chosen_word = rand()%nwords;
}

void play_game()
{
	//in linux
	system("clear");

	//in window
	//system("cls");

	char* answer = word[index_chosen_word];
	char* hangword;
	int len = strlen(answer);
	
	hangword = (char*)malloc(len*sizeof(char));
	strncpy(hangword,answer,len-1);

	//do not setting zero in Number Of blind
	int loopcnt;
	while(!(loopcnt = rand()%len))
	{}

	int NumberOfBlind = loopcnt;

	//loop to blind char.
	while(loopcnt)
	{
		//random index is setting blind
		int idx = rand()%len;
		if(hangword[idx] != '_')
		{
			hangword[idx] = '_';
			loopcnt--;
		}
	}


	int Try =0;
	int TimeToDeath = 10+1;

	//for check input duplication
	char duptable[10+1]={0,};

	//It just pictures. 
	char* hangman[10+1]={"\n\n\n\n\n\n\n\n\n\n\n\n",
			     "\n\n\n\n\n\n\n\n\n\n\n\n----------------",
			   "\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+----------------\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\t\t|\n\t|\t\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\t       /|\n\t|\t\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\t       /|\\\n\t|\t\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\t       /|\\\n\t|\t\t|\n\t|\t       /\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------",
			   "\t+---------------+\n\t|\t\t|\n\t|\t\t|\n\t|\t\tO\n\t|\t       /|\\\n\t|\t\t|\n\t|\t       / \\\n\t|\n\t|\n\t|\n\t|\n\t|\n--------+-------"};


	int dupidx = 0;
	while(TimeToDeath != Try)
	{
		//linux
		system("clear");

		//windwos
		//system("cls");

		char letter;
		bool iscorrect = 0;

		//print picture and word
		printf("%s\n\n",hangman[Try]);
		for(int i =0; i < len ; i++)
			printf("%c  ",hangword[i]);


		//print gussed letters
		printf("\n\nYOU GUESSED LETTER :");
		for(int i = 0; i<strlen(duptable); i++)
		{
			printf(" %c ",duptable[i]);
		}
		printf("\n\n");

		//get input
		printf("Pick a letter >> ");
		scanf(" %c",&letter);

		//check duplicate
		if(strchr(duptable,letter))
		{
			printf("Sorry, already guessed. ' %c '\n",letter);
			sleep(1);
			continue;
		}

		//add letter to duplicate table
		duptable[dupidx++] = letter;


		//check to answer
		for(int i = 0; i<len; i ++)
		{
			if(hangword[i] == '_' && answer[i] == letter)
			{	
				hangword[i] = letter;
				iscorrect = 1;
				NumberOfBlind -= 1;
			}	
		}

		//All letters are correct
		if(!NumberOfBlind)
		{
			printf("YOU ALIVE!!\n");
			break;
		}

		//if letter is miss to answer, try + 1
		if(!iscorrect)
			Try++;
	}

}

int main(void)
{
	char command;
	initialize_number_generator();
	read_dictionary();
	while (1) 
	{
		choose_word();
		play_game();
		printf("Do you want to play again ? Y/N ");
		scanf(" %c", &command);
		if (!(command == 'y' || command == 'Y'))
			break;
		printf("\n");
	}
	return 0;
}
