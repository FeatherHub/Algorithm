#pragma once

class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci() = default;

	int Fibonacci_Brute(int n);
	int Fibonacci_Memo(int n);
	int Fibonacci_Iter(int n);

private:
	int _Fibonacci_Memo(int* memo, int n);

	const int NOT_CALCULATED = -1;
};