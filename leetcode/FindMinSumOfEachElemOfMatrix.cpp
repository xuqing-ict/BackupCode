//对于一个矩阵。找出一个数字的集合的最小和，使得这个集合中的元素在数组中仅在某一行或者某一列出现
//类似8皇后问题！@！！！！！！
//
#include <iostream>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
using namespace std;

void helper(vector<vector<int> > &matrix, int &minSum, int curRowIndex, const int maxRowIndex, int curSum, vector<bool> &visited , const int maxColumnIndex)
{
	if (curRowIndex > maxRowIndex)
	{
		if (curSum < minSum)
		{
			minSum = curSum;
		}
		return;
	}
	for(int i = 0 ; i <= maxColumnIndex ; ++i)
	{
		if (visited[i]  == false)
		{
			visited[i] = true;
			curSum += matrix[curRowIndex][i];
			helper(matrix, minSum, curRowIndex + 1, maxRowIndex, curSum, visited, maxColumnIndex);
			visited[i] = false;
		}
	}
}

int FindMinSum(vector<vector<int> > &matrix)
{	
	if(matrix.empty())
	{
		return 0;
	}
	int row = matrix.size();
	int column = matrix[0].size();
	vector<bool> visited(column, false);
	int ret = INT_MAX;
	helper(matrix, ret, 0, row-1, 0, visited , column-1);
	return ret;
}

int main()
{
	vector<vector<int> > matrix;
	vector<int> a;
	a.push_back(0);
	a.push_back(-1);
	matrix.push_back(a);
	a.clear();
	a.push_back(5);
	a.push_back(3);
	matrix.push_back(a);

	cout << FindMinSum(matrix) << endl;
	string str = "-12";
	cout << atoi(str.c_str()) << endl;
	return 0;
}
