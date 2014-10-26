#include <bits/stdc++.h>
using namespace std;

int find(const vector<int> &vec)
{
	const int n =vec.size();
	int candidate, count=0;
	for(int i=0;i<n;++i)
	{
		if(count == 0)
		{
			candidate = vec[i];
			count = 1;
		}
		else
		{
			--count;
		}
	}
	return candidate;
}

int main()
{
	vector<int> vec = {1,2,3,4,4,4,4,4,4};
	cout << find(vec) << endl;
	return 0;
}
