#include <iostream>
using namespace std;

#include "Fibonacci.h"

int main()
{
	Fibonacci fibo;
	
	for (int n = -1; n <= 10; n++)
	{
		cout << "Fibo Brute n=" << n << " : " << fibo.Fibonacci_Brute(n) << endl;
		cout << "Fibo Memo n=" << n << " : " << fibo.Fibonacci_Memo(n) << endl;
		cout << "Fibo Iter n=" << n << " : " << fibo.Fibonacci_Iter(n) << endl;

		cout << endl;
	}

	return 0;
}