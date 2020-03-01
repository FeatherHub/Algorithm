#include "Solution.h"

#include <iostream>
#include <stack>

//시간재서 문제풀이 연습하기

//string, istringstream

//화이트보드에 해보는 연습(손코딩)
//디버깅에 의존 x

//확률문제 - 주사위

//핵심 알고리듬 문제
//	-피보나치 : 선형적인 재귀식
//	-조합/순열 : tree 재귀식
//	-자료구조 : search, sort, dynamic, greedy

//정리
//확률, 핵심 알고리즘, STL,
//프로그래밍 언어, 운영체제, 네트워크,
//그래픽스, 데이터베이스, 게임구조 ...

//기계적으로

void Solution::ReverseWords(string& s)
{
	char* cstr = (char*)s.c_str();
	stack<int> blankPosStack;
	
	blankPosStack.push(-1);
	for (int i = 0; i < s.size(); i++)
	{
		if (cstr[i] == ' ')
		{
			blankPosStack.push(i);
		}
	}

	string reversedStr;
	while (blankPosStack.empty() == false)
	{
		auto posOfBlank = blankPosStack.top();
		blankPosStack.pop();

		int posOfChar = posOfBlank + 1;
		while (posOfChar < s.size() && 
			cstr[posOfChar] != ' ' &&  
			cstr[posOfChar] != '\0') 
		{
			reversedStr.push_back(cstr[posOfChar++]);
		}
		reversedStr.push_back(' ');
	}

	s.swap(reversedStr);
}