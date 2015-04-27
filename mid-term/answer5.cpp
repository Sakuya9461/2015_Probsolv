#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define bool char
#define COUNT 100000
int main()
{
	int NumberOfGuest = 2;
	int Bob = 0;
	int cnt = COUNT;
	
	//seed 초기화
	srand(time(NULL));

	while (NumberOfGuest<=100)
	{
		int all_known = 0;
		cnt = COUNT;
		while (cnt--)
		{
			//모든 참석자가 소문을 못들은 상태.
			bool *is_hear = (bool*)malloc(sizeof(bool)*NumberOfGuest);
			memset(is_hear, false, sizeof(bool)*NumberOfGuest);
			int KnownPeople = 0;
			
			//Bob이 소문을 들음. 알고 있는 사람의 카운트 수가 증가함.
			is_hear[Bob] = true;
			KnownPeople++;

			//마지막으로 소문을 들은 사람은 Bob이다. 그리고 전달한 사람도 Bob이다.
			int LastGuest = Bob;
			int LastSender = Bob;

			//2명일때 무한루프를 돌게 되므로 미리방지.
			if (NumberOfGuest == 2)
			{
				all_known = COUNT;
				break;
			}
			//Bob을 제외한 다른 한사람에게 소문을 퍼뜨린다.
			while (1)
			{
				int NextGuest = rand() % NumberOfGuest;

				//다음소문을 들을 사람이 마지막 전달자와 마지막 소문을 들은사람을 제외한다.
				if (NextGuest == LastSender)
					continue;
				if (NextGuest == LastGuest)
					continue;

				//그렇게 사람을 하나 뽑으면 이 사람이 마지막으로 들은사람이 되고
				//나에게 전달해준사람은 마지막으로 전해준 사람이된다.
				LastSender = LastGuest;
				LastGuest = NextGuest;

				//마지막 사람이 소문을 들은게 아니라면, 전달한다.
				//이 경우, 알게되는 사람의 수가 증가한다.
				if (!is_hear[NextGuest])
				{
					is_hear[NextGuest] = true;
					KnownPeople++;
					continue;
				}
				//만약 그 사람이 소문을 들은경우, 소문은 더이상 퍼지지 않는다.
				else
					break;
			}
			if (NumberOfGuest == KnownPeople)
				all_known++;
		}
		printf("%d : %f%", NumberOfGuest, all_known/(double)COUNT);
		NumberOfGuest++;
	}
	
}