#include <rand.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandTest(int testType)
{
	if (testType == 0)
	{
		printf("This testType 0 Repeat Rand After Srand \n");

		srand(time(NULL));

		for (int i = 0; i < 30; i++)
		{
			printf("Test %dth \n", i+1);
			RepeatRandAfterSrand();
		}
	}
	else
	{
		printf("This testType 0 Repeat Rand With Srand \n");

		for (int i = 0; i < 30; i++)
		{
			printf("Test %dth \n", i+1);
			RepeatRandWithSrand();
		}
	}
	printf("\n");
}

void RepeatRandAfterSrand()
{
	for (int i = 0; i < 100; i++)
	{
		printf("%5d ", rand() % 100);
	}
	printf("\n");
}

void RepeatRandWithSrand()
{
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		printf("%5d ", rand() % 100);
	}
	printf("\n");
}
