/*
 * 题目:
 * 输入一个整形数组,数组里有正数也有负数。
 * 数组中连续的一个或多个整数组成一个子数组,每个子数组都有一个和。
 * 求所有子数组的和的最大值。要求时间复杂度为 O(n)。
 *
 */


#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
const int MAX = 100;

int maxSubArray(int A[], int len)
{
	int *ret = new int[len];
	ret[0] = A[0];
	for(int i = 1 ; i < len; ++i)
	{
		ret[i] = max(ret[i-1]+A[i],A[i]);
	}
	int maximum = ret[0];
	for(int i = 0;i < len; ++i)
		if (maximum < ret[i])
			maximum  = ret[i];
	delete [] ret;
	return maximum;
}



int maxSubArray2(int A[], int len, int &left, int &right)
{
	int maxSum = 0;
	int i = 0;
	int temp = 0,lIndex = 0;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp < 0) 
		{
			lIndex = i;
			temp = 0;
		}
		temp += A[i];
		if(temp > maxSum)
		{
			maxSum = temp;
			left = lIndex;
			right = i;
		}
	}
	return maxSum;
}

int maxSubArray3(int A[], int len, vector<int >&ret )
{
	int maxSum = 0;
	int i = 0;
	int temp = 0;
	vector<int> sub;

	for(int i = 0; i < len ; ++i)
	{
		if(temp < 0) 
		{
			sub.clear();
//			sub.push_back(A[i]);
			temp = 0;
		}
		sub.push_back(A[i]);
		temp += A[i];
		if(maxSum < temp) 
		{
			maxSum = temp;
			ret = sub;
		}
	}
	return maxSum;
}



int main()
{
	int A[] = {4,3,-4,1,5,-3,4,-4};
	/*unsigned int base = 1;
	int val =  A[0];
	int temp = 32;
	while(val && (temp--))
	{
		cout << ((val & base)?1:0) << " ";
		val = val >> 1;
	}
	*/
	static int left = 0;
	static int right = 0;
	int len = sizeof(A)/sizeof(int);
	cout << maxSubArray(A, len) << endl;
	cout << maxSubArray2(A, len,left,right) << endl;
	cout << left << " " << right << endl;
	vector<int> ret;
	cout << maxSubArray3(A, len,ret) << endl;

	for(int i=0;i<ret.size();++i)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}
