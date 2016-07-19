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

int ShortestPathDCG::BottomUp(Vertex* s, Vertex* d, int vertexNum)
{
	return 0;
}
