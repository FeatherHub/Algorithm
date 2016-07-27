#include "AnActivity.h"
#include "Activity.h"
#include <algorithm>

int AnActivity::Greedy(Activity* actArr, int actNum)
{
	std::sort(actArr, actArr + actNum, [](const Activity& act1, const Activity& act2)->bool
	{
		return act1.Finish() < act2.Finish() ? true : false;
	});

	int selectedActNum = 0;
	int lastFinished = 0;

	for (int i = 0; i < actNum; i++)
	{
		if (actArr[i].Start() >= lastFinished)
		{
			selectedActNum++;
			lastFinished = actArr[i].Finish();
		}
	}

	return selectedActNum;
}
