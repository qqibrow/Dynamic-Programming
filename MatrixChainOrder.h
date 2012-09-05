#pragma once

#include "IndexMatrix.h"
#include <vector>
#include <iostream>
class MatrixChainOrder
{
public:	
	MatrixChainOrder(std::vector<int> inputp);

	void doDP();
	void outputFinalResult(std::ostream& out);
	void RecursiceOutput(std::ostream& out, int begin, int end);
	~MatrixChainOrder(void);
	IndexMatrix m,s;
	
private:
	MatrixChainOrder(void);
	int n;
	std::vector<int> matrixSizeSequence;
};

