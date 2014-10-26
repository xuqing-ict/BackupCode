#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

void helper(const int n ,const int k ,  int curLen ,  int curNumber, vector<int> &curState, vector<vector< int > > &ret)
{
	if(curLen >= k)
	{
		if (curNumber <= n)
		{
			ret.push_back(curState);
		}
		return;
	}
	
//	curState.push_back(curNumber);
//	从curNumber的下一个数字开始循环 
	for(int i = curNumber+1; i <= n; ++i)
	{
		curState.push_back(i);
		helper(n,k,curLen + 1, i, curState, ret);
		curState.pop_back();
	}
}

vector<vector<int> > combine(int n ,int k)
{
	vector< vector<int> > ret;
	vector<int> curState;
	//初始调用此函数时，curNumber为0.并且此时的curLen = 0
	helper(n,k,0,0,curState,ret);
	return ret;
}

int main()
{
	int n = 4, k = 3;
	vector<vector<int> > ret = combine(n,k);
	cout << ret.size() << endl;
	for(int i = 0 ; i < ret.size() ; ++i)
	{
		copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout, "\t"));
		cout << endl;
	}
	return 0;
}
