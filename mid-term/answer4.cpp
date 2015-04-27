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
	//배열선언
	arr = (int*)malloc(sizeof(int)*N);

	//초기값은 중복될 일이 없다.
	scanf("%d", &arr[0]);
	
	//첫값은 이미 위에서 받아옴. i=1부터.
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &temp);
		is_dup = false;
		//받아온 값이 배열에 있나 검사
		for (int j = 0; j < N; j++)
		{
			if (arr[j] == temp)
				is_dup = true;
		}
		if (!is_dup)
			arr[cnt++] = temp;
	}

	//정렬
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

	//출력
	for (int i = 0; i < cnt; i++)	
		printf("%d ", arr[i]);
}