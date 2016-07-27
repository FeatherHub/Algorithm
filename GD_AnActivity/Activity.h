#pragma once

class Activity
{
public:
	Activity() 
	{}
	
	Activity(int s, int f) : start(s), finish(f) 
	{}
	
	int Start() const { return start; }
	int Finish() const { return finish; }

private:
	int start;
	int finish;
};
