#include<iostream>
#include <vector>
#include<cstdlib>
#include <limits.h>
using namespace std;
const int MAX = 100;


int maxSubArray(int A[], int len)
{
	vector<int> ret(len,0);
	ret[0] = A[0];
	for(int i = 1 ; i < len; ++i)
	{
		ret[i] = max(ret[i-1]+A[i],A[i]);
	}
	int maximum = ret[0];
	for(int i = 0;i < len; ++i)
		if (maximum < ret[i])
			maximum  = ret[i];
	return maximum;
}

int maxSubArray2(int A[], int len)
{
	int temp = 0, ret = INT_MIN;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp < 0)
		{
			temp = 0;
		}
		temp += A[i];
		if(ret < temp)
		{
			ret = temp;
		}
	}
	return ret;
}
int main()
{
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	/*unsigned int base = 1;
	int val =  A[0];
	int temp = 32;
	while(val && (temp--))
	{
		cout << ((val & base)?1:0) << " ";
		val = val >> 1;
	}
	*/
	int len = sizeof(A)/sizeof(int);
	cout << maxSubArray(A, len) << endl;
	cout << maxSubArray2(A, len) << endl;
	return 0;
}
