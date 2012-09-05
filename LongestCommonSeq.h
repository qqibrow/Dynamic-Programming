#pragma once
#include <vector>
#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

class LongestCommonSeq
{
public:
	void doDPbyMemorize();
	enum Direction{ TopLeft, Left, Up};
	void printLongestCommonSeq();
	LongestCommonSeq(std::vector<char>& X, std::vector<char>& Y);
	~LongestCommonSeq(void);
private:
	int loopUpTable(int m,  int n);
	
	void RecursizePrintAnswer(int m, int n);
	LongestCommonSeq(void);
	std::vector<char> xSeq,ySeq,seq;
	int longestLength,xSize,ySize;
	boost::numeric::ublas::matrix<int> opt;
	boost::numeric::ublas::matrix<Direction> path;

};

