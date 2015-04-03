#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	srand(time(NULL));
	//make car room
	int room[3]={0,};
	int testcase;
	int cnt_change = 0;
	int not_change = 0;
	scanf("%d",&testcase);
	while(testcase--)
	{
		int car = rand()%3;
		int showroom;
		int choice = rand()%3;
		int change;
		room[car] = 1;
		while(1)
		{
			showroom = rand()%3;
			
			//must not choise and car
			if(showroom == car || showroom == choice)
				continue;
			else
				break;
		}
	
		//change swap
		while(1)
		{
			change = rand()%3;
			if(choice == change || showroom == change)
				continue;
			else
				break;
		}
		if(room[change])
			cnt_change++;
		if(room[choice])
			not_change++;
		memset(room,0,3*sizeof(int));
	}
	printf("Change :: %d\nChoise :: %d\n",cnt_change,not_change);	
}
