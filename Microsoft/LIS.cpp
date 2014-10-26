#include <bits/stdc++.h>

using namespace std;

int LIS(int A[], int n)
{
	assert(A!=NULL);
	if(n <= 1) return n;
	vector<int> dp(n,INT_MAX);
	for(int i = 0 ; i < n ; ++i)
	{
		*(lower_bound(dp.begin(),dp.end(),A[i])) = A[i];
	}
	return lower_bound(dp.begin(),dp.end(),INT_MAX)-dp.begin();
	
}
int main()
{
	int A[] = {3,4,1,3,5,-1,0,-3};
	int n = sizeof(A)/sizeof(int);
	cout << LIS(A,n) << endl;
	return 0;
}
