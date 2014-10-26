//在数组A中寻找是否存在4个数的和为sum
#include <iostream>
#include <algorithm>

#include <vector>
#include <cassert>

using namespace std;

bool find4Sum(const vector<int> &A, int sum)
{
	int n = A.size();
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < n ; ++j)
			for(int k = 0 ;k < n ;++k)
				for(int l = 0 ; l < n ; ++l)
					if (A[i] + A[j]+A[k] + A[l] == sum)
					{
						cout << A[i] << " " << A[j] << " " << A[k] << " " << A[l] << endl;
						return true;
					}

	return false;
}

bool binary_search(const vector<int> &A, const int target)
{
	int n = A.size();
	int left = 0, right = n-1;
	while(left <= right)
	{
		int mid = left + (right-left)/2;
		if (A[mid] == target) return true;
		else if (A[mid] > target)
		{
			right = mid-1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return false;
}


bool findSum2(const vector<int> &A, const int sum)
{
	int n = A.size();
	vector<int> sum2(n*n,0);
	int  k = 0;
	for(int i = 0 ; i < n; ++i)
		for(int j = 0 ; j < n ; ++j)
			sum2[k++] = A[i] + A[j];
	assert(k == n*n);
	sort(sum2.begin(), sum2.end());
	for(int i = 0 ; i < k ; ++i)
		if ( binary_search(sum2, sum-sum2[i]))
			return true;
	
	return false;
}

int main()
{
	int data[] = {-1, 2};
	vector<int> A(data, data+sizeof(data)/sizeof(int));
	int sum = 8;
	if (findSum2(A,sum))
	{
		cout << "find..." << endl;
	}
	
	//test binary_search
	sort(A.begin(), A.end());
	assert(binary_search(A, 2));
	return 0;
}
