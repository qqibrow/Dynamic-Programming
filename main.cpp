
#include <iostream>
#include <vector>
#include <fstream>
#include "MatrixChainOrder.h"
#include "LongestCommonSeq.h"
#include "LongestIncreasingSeq.h"


using namespace std;

int main()
{	
	vector<int> p;

	
	ifstream cin("matrix.in");
	int num;
	cin>>num;

	

	int single;
	for (int i = 0; i < num; i++)
	{
		cin>>single;
		p.push_back(single);
	}

	MatrixChainOrder matrixChain(p);

	matrixChain.doDP();

	cout<<" print the m:\n";
	matrixChain.m.print();
	cout<<" print the s:\n";
	matrixChain.s.print();

	cout<<" print the result:\n";
	matrixChain.outputFinalResult(cout);


	char xSeq[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	char ySeq[6] = {'B', 'D', 'C', 'A', 'B', 'A'};

	LongestCommonSeq m_longestCommonSeq(vector<char>(xSeq, xSeq + 7),vector<char>(ySeq, ySeq + 6) );
	m_longestCommonSeq.doDPbyMemorize();
	m_longestCommonSeq.printLongestCommonSeq();
	
	cout<<endl;
	int test[6] = {11, 9, 3, 10, 7, 2};
	LongestIncreasingSeq longestIncreasingSeq(vector<int>(test, test + 6));
	longestIncreasingSeq.doDp();
	int answer = longestIncreasingSeq.getAnswer();
	longestIncreasingSeq.printAnswer();

	return 0;

}