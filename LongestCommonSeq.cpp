#include "LongestCommonSeq.h"


LongestCommonSeq::LongestCommonSeq(void)
{
}

LongestCommonSeq::LongestCommonSeq( std::vector<char>& X, std::vector<char>& Y ):
	xSeq(X.begin(), X.end()), ySeq(Y.begin(), Y.end()), opt(X.size()+1, Y.size()+1), 
		path(X.size()+1, Y.size()+1)
{
	longestLength = 0;
 	xSize = xSeq.size();
 	ySize = ySeq.size();
// 	for( int i = 0; i <= opt.size1(); i++)
// 		for( int j = 0; j <= opt.size2(); j++)
// 			opt(i,j) = 0;

}


LongestCommonSeq::~LongestCommonSeq(void)
{
}

void LongestCommonSeq::doDPbyMemorize()
{
	loopUpTable(xSize, ySize);
	for( int i = 0; i < opt.size1(); i++)
	{
		for( int j = 0; j < opt.size2(); j++)
			std::cout<<opt(i,j)<<' ';
		std::cout << '\n';
	}

}

int LongestCommonSeq::loopUpTable( int m, int n )
{
	if ( m > 0 && n > 0)
	{
		if ( xSeq[m-1] == ySeq[n-1])
		{
			opt(m,n) = loopUpTable(m - 1, n - 1) + 1;
			path(m,n) = TopLeft;
		}
		else 
		{
			int lm = loopUpTable(m - 1, n);
			int rm = loopUpTable(m, n - 1);
		
			if( lm > rm)
			{
				opt(m,n) = lm;
				path(m,n) = Left;
			}
			else
			{
				opt(m,n) = rm;
				path(m,n) = Up;
			}
		}
	}
	else
		opt(m,n) = 0;

	return opt(m,n);
}

void LongestCommonSeq::printLongestCommonSeq()
{
	RecursizePrintAnswer(xSize, ySize);
}

void LongestCommonSeq::RecursizePrintAnswer( int m, int n )
{
	if( m == 0 || n == 0)
		return;
	
	if( path(m,n) == TopLeft)
	{
		RecursizePrintAnswer(m - 1, n - 1);
		std::cout<<xSeq[m-1];
	}
	else if( path(m, n) == Up)
		RecursizePrintAnswer(m, n-1);
	else
		RecursizePrintAnswer(m-1, n);
}
