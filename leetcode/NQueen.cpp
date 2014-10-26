#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


bool isSafety(int row, int column, vector<int> &curState)
{
	//第0行的皇后可以随便放
	if (row == 0)
	{
		return true;
	}
	for(int i =  0; i < row ; ++i)
	{
		if(curState[i] == column ||
				abs(curState[i] - column) == abs(row-i))
		{
			return false;
		}
	}
	return true;
}

/*
void helper(int total, int row, vector<int> &curState, int &count)
{
	if (row >= total)
	{
		++count;
		return;
	}
	for(int column = 0; column < total; ++column)
	{
		if (isSafety(row, column, curState))
		{
			curState[row] = column;
			helper(total, row + 1, curState, count);
		}
	}

}

int totalQueen(int n)
{
	vector<int> curState(n, -1);
	int count = 0;
	helper(n,0,curState,count);
	return count;
}
*/
void addVector(vector<vector<string> > & ret, vector<int> &curState)
{
	string temp;
	vector<string> tempVec;
	for(int i = 0 ; i < curState.size() ; ++i)
	{
		int j = 0;	
		temp.clear();
		while( j < curState[i])
		{
			temp += '.';
			++j;
		}
		temp += 'Q';
		++j;
		while( j < curState.size())
		{
			temp += '.';
			++j;
		}
		tempVec.push_back(temp);
	}
	ret.push_back(tempVec);
}

void helper(int total, int row, vector<int> &curState, vector< vector< string > > & ret)
{
	if (row >= total)
	{
		addVector(ret, curState);
		return;
	}
	for(int column = 0; column < total; ++column)
	{
		if (isSafety(row, column, curState))
		{
			curState[row] = column;
			helper(total, row + 1, curState, ret);
		}
	}

}


vector<vector< string > > solveNQueens(int n)
{
	vector< vector < string > > ret;
	vector<int> curState (n,-1);
	helper(n,0,curState, ret);
	return ret;
}

int main()
{
	int n = 4;
	vector<vector<string > > ret = solveNQueens(n);
	for(int i = 0 ; i < ret.size() ; ++i)
	{
		copy(ret[i].begin(), ret[i].end() , ostream_iterator<string>(cout, "\n"));
		cout << endl;
	}
	return 0;
}
