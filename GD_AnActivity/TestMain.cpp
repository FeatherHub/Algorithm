#include "AnActivity.h"
#include "Activity.h"
#include <iostream>

int main()
{
	Activity actArr[] = {
		Activity(1, 4),
		Activity(3, 5),
		Activity(0, 6),
		Activity(5, 7),
		Activity(3, 9),
		Activity(5, 9),
		Activity(6, 10),
		Activity(8, 11),
		Activity(8, 12),
		Activity(2, 14),
		Activity(12, 14),
	};

	int actNum = sizeof(actArr) / sizeof(Activity);

	int res = AnActivity::Greedy(actArr, actNum);
	std::cout << res << std::endl;

	return 0;
}