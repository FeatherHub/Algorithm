#pragma
#include <vector>

// SortTest 기능
// 테스트 데이터	: 다양한 종류의 테스트 데이터를 관리한다
// 성능 테스트	: 기능 수행에 얼마나 시간이 걸렸는지 측정한다

class SortTest
{
public:
	SortTest();
	~SortTest();
	
	void TestAlgorithm(void sorter(int*, int), const char* algoName);

private:
	void ResetData();
	void PrintArray(const std::vector<int>& v);
	void TestSet(void sorter(int*, int), const std::vector<int>& v);
	bool IsSorted(int* arr, int n);
	
	std::vector<int> m_data_one;
	std::vector<int> m_data_two;
	std::vector<int> m_data_three;
	std::vector<int> m_data_identity;
	std::vector<int> m_data_asc;
	std::vector<int> m_data_desc;
	std::vector<int> m_data_random1;
	std::vector<int> m_data_random2;
};