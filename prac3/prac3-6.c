#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

#define bool char
#define NUMBER 0
#define SHAPE 1

int num_in_rank[NUM_RANKS+3];
int num_in_suit[NUM_SUITS];

char card_list[5*2+1];
char card[2+1];

bool check_dup(char* inp);
void read_cards();
void analyze_hand();
void init_data();
int check_flush();
int check_straight();
int check_four_cards();
int check_three_cards();
int count_paris();

int main(void)
{
	while(1) 
	{
		read_cards();
		analyze_hand();
	} 
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank, suit;
	init_data();
	int cards_read = 0;
	int idx = 0;

	while(cards_read < NUM_CARDS)
	{
		//window
		fflush(stdin);
		//linux
		fpurge(stdin);

		printf("Enter a card :");
		rank_ch = getchar();
		switch(rank_ch)
		{	
			case 'a': rank = 1; break;
			case '2': rank = 2; break;
			case '3': rank = 3; break;
			case '4': rank = 4; break;
			case '5': rank = 5; break;
			case '6': rank = 6; break;
			case '7': rank = 7; break;
			case '8': rank = 8; break;
			case '9': rank = 9; break;
			case 't': rank = 10; break;
			case 'j': rank = 11; break;
			case 'q': rank = 12; break;
			case 'k': rank = 13; break;
		
			default:
				printf("IDK your input. try again\n");
				continue;
		}
		//card number
		card[NUMBER]=rank_ch;

		suit_ch = getchar();
		switch(suit_ch)
		{
			case 'c' : suit = 0; break;
			case 'd' : suit = 1; break;
			case 'h' : suit = 2; break;
			case 's' : suit = 3; break;
			default:
				printf("IDK your input. try again\n");
				continue;
		}

		//card shape		
		card[SHAPE] = suit_ch;
				
		if(strstr(card_list,card))
		{
			printf("You have already this card. try again.\n");
			continue;
		}

		//make list		
		strcat(card_list,card);

		while((ch = getchar()) != '\n'){}
		num_in_rank[rank]++;
		num_in_suit[suit]++;
		if(rank ==1)
			num_in_rank[14]++;
		
		cards_read++; 
		
	}
	memset(card_list,0,5*2+1);
}
void analyze_hand(void)
{
	int count;
	if(check_straight())
	{
		printf("STRAIGHT");
	}
	if(check_flush())
	{
		printf("FLUSH");
	}
	if(check_four_cards())
	{
		printf("FOUR CARDS");
	}

	if(check_three_cards())
	{
		printf("TRIPLE");
	}
	if((count = count_paris()))
	{
		printf("PAIR :: %d",count);
	}
	printf("\n");
}

void init_data()
{
	int rank, suit;
	for( rank=0; rank<NUM_RANKS+3; rank++)
		num_in_rank[rank] = 0;
	for (suit =0; suit<NUM_SUITS; suit++)
		num_in_suit[suit] = 0;
}

int check_flush()
{
	for(int i =0; i <NUM_SUITS; i++)
	{
		if(num_in_suit[i] ==5)
			return 1;
	}
	
	return 0;
}

int check_straight()
{
	int check = 0;
	
	if(!(num_in_rank[1] ^ num_in_rank[2]))
		num_in_rank[14] = 0;
	for(int i =1; i <=NUM_RANKS+2; i++)
	{
		if(num_in_rank[i]^num_in_rank[i+1])
		{
			check++;	
		}
	}

	if(check<=2)
		return 1;
	return 0;
}

int check_four_cards()
{
	for(int i =0; i <NUM_RANKS; i++)
	{
		if(num_in_rank[i] == 4)
			return 1;
	}
	return 0;
}

int check_three_cards()
{
	for(int i =1; i <NUM_RANKS; i++)
	{
		if(num_in_rank[i] ==3)
			return 1;
	}
	return 0;
}

int count_paris()
{
	int count =0;
	for(int i=1; i<NUM_RANKS; i++)
	{
		if(num_in_rank[i] == 2)
			count++;
	}
	return count;
}
