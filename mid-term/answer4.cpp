#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define bool char
#pragma warning(disable:4996)
int main()
{
	int N;
	int* arr;
	int temp;
	int cnt = 1;
	bool is_dup = false;
	
	scanf("%d", &N);
	//�迭����
	arr = (int*)malloc(sizeof(int)*N);

	//�ʱⰪ�� �ߺ��� ���� ����.
	scanf("%d", &arr[0]);
	
	//ù���� �̹� ������ �޾ƿ�. i=1����.
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &temp);
		is_dup = false;
		//�޾ƿ� ���� �迭�� �ֳ� �˻�
		for (int j = 0; j < N; j++)
		{
			if (arr[j] == temp)
				is_dup = true;
		}
		if (!is_dup)
			arr[cnt++] = temp;
	}

	//����
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i; j < cnt; j++)
		{
			if (arr[j]<=arr[i])
			{
				int tmp = arr[i];
				arr[i]= arr[j];
				arr[j] = tmp;
			}
		}
	}

	//���
	for (int i = 0; i < cnt; i++)	
		printf("%d ", arr[i]);
}