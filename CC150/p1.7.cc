//若矩阵中的某个元素为0，则将该行该列均清0
#include <bits/stdc++.h>
using namespace std;

void ClearZero(vector<vector<int> > &matrix)
{
	if(matrix.empty()) return;
	
	int m = matrix.size();
	int n = matrix[0].size();
	bool row = false, column = false;

	for(int i = 0 ; i < m ; ++i)
		if(matrix[i][0] == 0)
			row = true;

	for(int i = 0 ; i < n ; ++i)
		if(matrix[0][i] == 0)
			column = true;

	for(int i = 1 ; i < m ; ++i)
	{
		for(int j = 1 ; j < n ; ++j)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for(int i = 1 ; i < m;++i)
		if(matrix[i][0] == 0)
			fill(matrix[i].begin(), matrix[i].end(),0);
	for(int j = 1 ; j < n;++j)
		if(matrix[0][j] == 0)
		{
			for(int i = 0 ; i< m ;++i)
				matrix[i][j] = 0;
		}
	if(row)
		for(int i = 0 ; i < m; ++i) 
			matrix[i][0] =0;
	if(column)
		for(int i = 0 ; i < n; ++i) 
			matrix[0][i] =0;
}
int main()
{
	vector<vector<int> > matrix = {{5,5,6},{1,0,3},{4,5,6}};
	for(int i = 0 ; i < matrix.size(); ++i)
	{
		for(int j  = 0 ; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	ClearZero(matrix);
	for(int i = 0 ; i < matrix.size(); ++i)
	{
		for(int j  = 0 ; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}
