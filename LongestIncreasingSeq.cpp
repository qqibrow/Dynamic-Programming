#include "LongestIncreasingSeq.h"


LongestIncreasingSeq::LongestIncreasingSeq(void)
{
}

LongestIncreasingSeq::LongestIncreasingSeq( std::vector<int> seq ):xSeq(seq.begin(), seq.end())
{

}


LongestIncreasingSeq::~LongestIncreasingSeq(void)
{
}

void LongestIncreasingSeq::doDp()
{
	if(xSeq.size() < 2)
		return;

	//init
	opt.resize(xSeq.size(),0);
	path.resize(xSeq.size(),-1);
	opt[0] = 1;

	for( int x = 1; x < xSeq.size(); x++)
	{
		opt[x] = 0;
		int index = -1;
		for ( int k = x - 1; k >= 0; k--)
		{
			if ( xSeq[x] > xSeq[k] && opt[k] > opt[x] )
			{
				opt[x] = opt[k];
				index = k;
			}			
		}
		opt[x] = opt[x] + 1;
		path[x] = index;
	}

	int max = -1;
	for( int i = 0; i < opt.size(); i++)
		if ( opt[i] > max)
		{
			max =  opt[i];
			maxIndex = i;
		}
}

int LongestIncreasingSeq::getAnswer()
{
	return opt[maxIndex];
	
}

void LongestIncreasingSeq::printAnswer()
{
	RecursivePrint(maxIndex, opt[maxIndex]);
}

void LongestIncreasingSeq::RecursivePrint( int n, int length)
{
	if(length == 0)
		return;
	else
	{
		RecursivePrint( path[n], length - 1);
		std::cout<< xSeq[n] <<" ";
	}
}
