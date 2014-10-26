#include <bits/stdc++.h>
using namespace std;

void reverse(vector<vector<int> > &Vec)
{
	int m = Vec.size();
	if (m ==0)
	{
		return;
	}
	int n = Vec[0].size();
	assert( m == n );
	int up = 0 , down = m-1;
	while(up < down)
		swap(Vec[up++],Vec[down--]);
	for(int i = 0 ; i < m ; ++i)
		for(int j = i+1; j < n ; ++j)
			swap(Vec[i][j], Vec[j][i]);
	return;
}
int main()
{
	vector<vector<int> > A = {{1,2,3},{4,5,6},{7,8,9}};
	reverse(A);
	for(int i=0; i < A.size();++i)
	{
		for(int j = 0 ; j < A[i].size(); ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
