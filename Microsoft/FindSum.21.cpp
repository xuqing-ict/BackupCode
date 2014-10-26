#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void helper(const int n, const int m, int curSum, int curIndex, vector<int> &cur, vector<vector<int> > &ret)
{
	if (curIndex > n)
	{
		if(curSum == m)
		{
			ret.push_back(cur);
		}
		return;
	}
	if (curSum > m)
	{
		return;
	}
	cur.push_back(curIndex);
	helper(n,m,curSum+curIndex,curIndex + 1, cur,ret );
	cur.pop_back();
	helper(n,m,curSum,curIndex+1,cur, ret);
}
vector<vector<int> > findSum(const int n , const int m )
{
	vector<vector<int> > ret ;
	if(n == 0 || m == 0) return ret;
	vector<int> cur;
	helper(n,m,0,1,cur,ret);
	return ret;
}
int main()
{

	int n = 10, m = 15;
	vector<vector<int> > ret = findSum(n,m);
	for(int i = 0 ; i < ret.size() ; ++i)
	{

		copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout,"\t"));
		cout << endl;
	}
	return 0;
}
