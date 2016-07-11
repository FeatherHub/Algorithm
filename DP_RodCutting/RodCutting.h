#pragma once

class RodCutting
{
public:
	int TopDown(int* priceTable, int rodLength);
	int Memo(int* priceTable, int rodLength);
	int BottomUp(int* priceTable, int rodLength);

private:
	int _Memo(int* priceTable, int* memo, int rodLength);
	int max(int a, int b) { return (a > b ? a : b); }

	const int NOT_CALCULATED = -1;
};