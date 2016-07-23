#include "Solution.h"

#include <iostream>
using namespace std;

int main()
{
	Solution sol;
	string s{ "The sky is blue." };
	
	cout << s << endl;
	sol.ReverseWords(s);
	cout << s << endl;
	
	return 0;
}