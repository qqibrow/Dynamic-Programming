#pragma once

#include <vector>
#include <iostream>

class LongestIncreasingSeq
{
public:
	LongestIncreasingSeq(void);
	LongestIncreasingSeq(std::vector<int> seq);
	void doDp();
	int getAnswer();
	void printAnswer();
	~LongestIncreasingSeq(void);
private:
	int maxIndex;
	void RecursivePrint(int n, int length);
	std::vector<int> xSeq;
	std::vector<int> opt;
	std::vector<int> path;
};

