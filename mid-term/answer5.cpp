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
	
	//seed �ʱ�ȭ
	srand(time(NULL));

	while (NumberOfGuest<=100)
	{
		int all_known = 0;
		cnt = COUNT;
		while (cnt--)
		{
			//��� �����ڰ� �ҹ��� ������ ����.
			bool *is_hear = (bool*)malloc(sizeof(bool)*NumberOfGuest);
			memset(is_hear, false, sizeof(bool)*NumberOfGuest);
			int KnownPeople = 0;
			
			//Bob�� �ҹ��� ����. �˰� �ִ� ����� ī��Ʈ ���� ������.
			is_hear[Bob] = true;
			KnownPeople++;

			//���������� �ҹ��� ���� ����� Bob�̴�. �׸��� ������ ����� Bob�̴�.
			int LastGuest = Bob;
			int LastSender = Bob;

			//2���϶� ���ѷ����� ���� �ǹǷ� �̸�����.
			if (NumberOfGuest == 2)
			{
				all_known = COUNT;
				break;
			}
			//Bob�� ������ �ٸ� �ѻ������ �ҹ��� �۶߸���.
			while (1)
			{
				int NextGuest = rand() % NumberOfGuest;

				//�����ҹ��� ���� ����� ������ �����ڿ� ������ �ҹ��� ��������� �����Ѵ�.
				if (NextGuest == LastSender)
					continue;
				if (NextGuest == LastGuest)
					continue;

				//�׷��� ����� �ϳ� ������ �� ����� ���������� ��������� �ǰ�
				//������ �������ػ���� ���������� ������ ����̵ȴ�.
				LastSender = LastGuest;
				LastGuest = NextGuest;

				//������ ����� �ҹ��� ������ �ƴ϶��, �����Ѵ�.
				//�� ���, �˰ԵǴ� ����� ���� �����Ѵ�.
				if (!is_hear[NextGuest])
				{
					is_hear[NextGuest] = true;
					KnownPeople++;
					continue;
				}
				//���� �� ����� �ҹ��� �������, �ҹ��� ���̻� ������ �ʴ´�.
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