#include <iostream>

// BAEKJOON PROBLEM: printing stars
// https://www.acmicpc.net/problem/2439

int main()
{
	int num = 0; //number of row and col

	std::cin >> num;

	char* strBuffer = new char[num+1];
	strBuffer[num] = '\0';

	for (int i = 0; i < num; i++)
	// Style I [0, num)
	// i=0 corresponds to [0 
	// i<num corresponds to num) 
	{
		// number of blank = (num-i) - 1
		// range of blank [0, num-i-1)
		for (int j = 0; j < (num - i - 1); j++)
		{
			strBuffer[j] = ' ';
		}
		// number of star = i + 1
		// range of star [num-i, num)
		for (int j = (num - i - 1); j < num; j++)
		{
			strBuffer[j] = '*';
		}

		std::cout << strBuffer << std::endl;
	}

	// for문의 경우 range expression의 형식은
	// [ ) 혹은 [ ] 중에 하나이다
	// 시작 부분이 [ 으로 고정되어 있다

	// number of elements in range 
	// range expr type I [a, b): b - a
	// range expr type II [a, b]: b - a + 1

	// quick tips
	// [a, b]			-> (b-a) + 1
	// (a, b)			-> (b-a) - 1
	// [a, b), (a, b]	-> (b-a)

	delete[] strBuffer;

	return 0;
}