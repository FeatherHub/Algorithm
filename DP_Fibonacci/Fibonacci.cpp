#include "Fibonacci.h"

Fibonacci::Fibonacci() : NOT_CALCULATED(-1)
{

}

int Fibonacci::Fibonacci_Brute(int n)
{
	if (n == 1) return 1;
	else if (n < 1) return 0;

	return Fibonacci_Brute(n - 1) + Fibonacci_Brute(n - 2);
}

int Fibonacci::Fibonacci_Memo(int n)
{
	if (n <= 0)
		return 0;

	int* memo = new int[n + 1]; // problem size: [0, n]
	
	for (int i = 0; i <= n; i++)
	{
		memo[i] = NOT_CALCULATED;
	}

	int res = _Fibonacci_Memo(memo, n);

	delete[] memo;

	return res;
}

int Fibonacci::_Fibonacci_Memo(int* memo, int n)
{
	if (memo[n] != NOT_CALCULATED)
		return memo[n];

	if (n < 2) 
		memo[n] = n;
	else	
		memo[n] = _Fibonacci_Memo(memo, n - 1) + _Fibonacci_Memo(memo, n - 2);
	
	return memo[n];


	/* Previous Code
		if(n<2)
		{
			memo[n] = n;
			return n;
		}

		int res = _Fibonacci_Memo(memo, n - 1) + _Fibonacci_Memo(memo, n - 2);
		memo[n] = res;
		return res;
	*/
}

int Fibonacci::Fibonacci_Iter(int n)
{
	if (n <= 0)
		return 0;

	int* memo = new int[n + 1]; //problem size: [0,n]

	//종료 조건 -> 초기값
	memo[0] = 0;
	memo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	int res = memo[n];
	
	delete[] memo;

	return res;
}
