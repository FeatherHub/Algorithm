#include <stdio.h>
#pragma warning(disable:4996)

// 파일로부터 데이터를 읽어 홀수의 합을 처리하라

// 데이터 해석, 데이터 특성 판단, 데이터 연산이
// 하나의 공간에서 동시에 처리하는 전략
// problem_analysis.txt 참고

int main(void)
{
	int test_size = 0;
	int cur_elem = 0;
	int elem_num = 0; // 1 <= en <= 3,000,000
	int res = 0;
	int i = 0, j = 0;

	freopen("input.txt", "r", stdin);

	scanf("%d", &test_size);

	for (i = 0; i < test_size; i++)
	{
		scanf("%d", &elem_num);
		for (j = 0; j < elem_num; j++)
		{
			scanf("%d", &cur_elem);
			
			if (cur_elem % 2 == 0) 
				continue;
			
			res += cur_elem;
		}

		printf("Test No.%d: %d \n", i+1, res);

		res = 0;
	}

	printf("\n");

	return 0;
}