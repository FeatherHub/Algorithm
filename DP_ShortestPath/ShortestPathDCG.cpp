#include "ShortestPathDCG.h"
#include "Vertex.h"

int ShortestPathDCG::TopDownMemod(Vertex* s, Vertex* d, int vertexNum)
{
	//vertexNum * vertexNum 2차원 테이블 생성
	int** memo = new int*[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		memo[i] = new int[vertexNum];
	}
	
	//테이블의 모든 원소를 NOT_CALCULATED로 초기화
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			memo[i][j] = Vertex::NOT_CALCULATED;
		}
	}

	int res = _TopDownMemod(s, d, memo, vertexNum);

	//테이블 삭제
	for (int i = 0; i < vertexNum; i++)
	{
		//열 삭제
		delete[] memo[i];
	}
	//행 삭제
	delete[] memo;

	return res;
}

//d로부터 s로 거슬러간다
//s를 만나게 되면 종료한다

//min( 최단거리(before d) + d를 가리키는 edge의 값 )

int ShortestPathDCG::_TopDownMemod(Vertex* s, Vertex* d, int** memo, int stepLen)
{
	if (s == d || stepLen == 0)
		return 0;

	int shortestPath = INT_MAX;
	int neightborId = -1;

	//자기를 가리키는 이웃들에 접근한다
	auto& edgeToMeList = d->EdgeToMeList();
	for (auto& e = edgeToMeList.begin(); e != edgeToMeList.end(); ++e)
	{
		auto neighborV = (*e)->StartV();
		int res;
		
		if (memo[neighborV->Id()][stepLen - 1] != Vertex::NOT_CALCULATED)
		{
			res = memo[neighborV->Id()][stepLen - 1] + (*e)->Val();
		}
		else
		{
			res = _TopDownMemod(s, neighborV, memo, stepLen - 1) + (*e)->Val();
		}

		shortestPath = min(res, shortestPath);
		neightborId = neighborV->Id();
	}

	memo[neightborId][stepLen - 1] = shortestPath;

	return shortestPath;
}

//source로부터 각 vertex까지의 최단거리를 테이블을 이용해서 계산한다
int ShortestPathDCG::BottomUp(Vertex* s, Vertex* d, int vertexNum)
{
	//vertexNum * vertexNum 2차원 테이블 생성
	Vertex*** table = new Vertex**[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		table[i] = new Vertex*[vertexNum];
	}

	//테이블의 모든 원소를 nullptr로 초기화
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			table[i][j] = nullptr;
		}
	}

	//Initialization
	s->ShortestPathWeight(0);
	table[s->Id()][0] = s;

	for (int step = 0; step < vertexNum-1; step++)
	{
		for (int vertexId = 0; vertexId < vertexNum; vertexId++)
		{
			if (table[vertexId][step] != nullptr)
			{
				auto& curV = table[vertexId][step];

				auto& edgeList = curV->EdgeToOtherList();
				for (auto& e = edgeList.begin(); e != edgeList.end(); ++e)
				{
					auto neighborV = (*e)->TargetV();

					int shortesPath = INT_MAX;
					int oldRes = INT_MAX;

					//이미 계산된 값이 있으면
					if (table[neighborV->Id()][step + 1] != nullptr)
					{
						//비교하기 위해 가져온다
						oldRes = table[neighborV->Id()][step + 1]->ShortestPathWeight();
					}

					int newRes = curV->ShortestPathWeight() + (*e)->Val();

					shortesPath = min(oldRes, newRes);

					//최단거리가 새로 갱신된 값이면 vertex의 값 변경
					if (shortesPath == newRes)
					{
						neighborV->ShortestPathWeight(shortesPath);
					}

					table[neighborV->Id()][step + 1] = neighborV;
				}
			}
		}
	}

	int shortest = INT_MAX;
	for (int step = 0; step < vertexNum; step++)
	{
		if (table[d->Id()][step] != nullptr)
		{
			int tmp = (table[d->Id()][step])->ShortestPathWeight();
			shortest = min(tmp, shortest);
		}
	}

	return shortest;
}
