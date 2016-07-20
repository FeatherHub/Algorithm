#pragma once

class Matrix
{
public:
	Matrix(int r, int c) : row(r), col(c) 
	{}
	
	int Row() { return row; }
	int Col() { return col; }

private:
	int row;
	int col;
};