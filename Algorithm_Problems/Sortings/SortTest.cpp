#include <SortTest.h>
#include <Windows.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <iomanip>

SortTest::SortTest()
{
	srand(time(NULL));

	ResetData();
}

SortTest::~SortTest()
{
}

void SortTest::PrintArray(const std::vector<int>& v)
{
	for (int i : v)
	{
		std::cout << std::setw(5) << i;
	}
	std::cout << std::endl;
}

void SortTest::TestSet(void sorter(int*, int), const std::vector<int>& v)
{
	std::cout << "Before: ";
	PrintArray(v);

	//TODO: 시간 측정
	sorter((int*)v.data(), v.size());
	std::cout << "After: ";
	PrintArray(v);

	system("pause");
}

void SortTest::TestAlgorithm(void sorter(int*, int), const char* algoName)
{
	std::cout << "Test of " << algoName << std::endl;

	TestSet(sorter, m_data_one);
	TestSet(sorter, m_data_two);
	TestSet(sorter, m_data_three);
	TestSet(sorter, m_data_identity);
	TestSet(sorter, m_data_asc);
	TestSet(sorter, m_data_desc);
	TestSet(sorter, m_data_random1);
	TestSet(sorter, m_data_random2);

	ResetData();
}

void SortTest::ResetData()
{
	int range = 1000;

	m_data_one.push_back(rand() % range);

	m_data_two.push_back(rand() % range);
	m_data_two.push_back(rand() % range);

	m_data_three.push_back(rand() % range);
	m_data_three.push_back(rand() % range);
	m_data_three.push_back(rand() % range);

	int idenNumber = rand() % range;
	m_data_identity.push_back(idenNumber);
	m_data_identity.push_back(idenNumber);
	m_data_identity.push_back(idenNumber);
	m_data_identity.push_back(idenNumber);
	m_data_identity.push_back(idenNumber);

	for (int i = 0; i < 15; i++) //odd number
	{
		m_data_asc.push_back(rand() % range);
	}
	//std::less -> return (_Left < _Right);
	std::sort(m_data_asc.begin(), m_data_asc.end(), std::less<int>());

	for (int i = 0; i < 16; i++) //even number
	{
		m_data_desc.push_back(rand() % range);
	}
	//std::grater -> return (_Left > _Right);
	std::sort(m_data_desc.begin(), m_data_desc.end(), std::greater<int>());

	for (int i = 0; i < 100; i++) //big number
	{
		m_data_random1.push_back(rand() % range);
	}

	for (int i = 0; i < 1000; i++) //bigger number
	{
		m_data_random2.push_back(rand() % range);
	}
}
