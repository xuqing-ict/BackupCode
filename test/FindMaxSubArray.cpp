/*
 * 给定数组，找到两个不相交的子数组，使得数组的差最大
 * */

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int max_sub(int A[], int n)
{
	vector<int> LeftMin(n,0);
	vector<int> RightMin(n,0);
	vector<int> LeftMax(n,0);
	vector<int> RightMax(n,0);

	int temp1 = 0, max = 0, min = 0, temp2 = 0;
	
	for(int i = 0 ; i < n ; ++i)
	{
		if(temp1 <= 0) temp1 = 0;
		if(temp2 >= 0) temp2 = 0;
		temp1 += A[i];
		temp2 += A[i];
		if(temp1 > max) max = temp1;
		if(temp2 < min) min = temp2;	
		LeftMax[i] = max;
		LeftMin[i] = min;
	}

	temp1 = temp2 = min = max = 0;
	for(int i = n-1 ; i >= 0 ; --i)
	{
		if(temp1 <= 0) temp1 = 0;
		if(temp2 >= 0) temp2 = 0;
		temp1 += A[i];
		temp2 += A[i];
		if(temp1 > max) max = temp1;
		if(temp2 < min) min = temp2;
		RightMax[i] = max;
		RightMin[i] = min;
	}

	copy(LeftMin.begin(), LeftMin.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(LeftMax.begin(), LeftMax.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(RightMin.begin(), RightMin.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(RightMax.begin(), RightMax.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	max= temp1 = 0;
	for(int i = 0 ; i < (n-1) ;++i)
	{
		if((temp1 = abs(LeftMin[i] - RightMax[i+1])) > max)
			max = temp1;
		if((temp1 = abs(LeftMax[i] - RightMin[i+1])) > max)
			max = temp1;
	}
	return max;

}



int main()
{	
	int data[] = {2,-1,-2,1,-4,2,8};
	int len = sizeof(data)/sizeof(int);

	cout << "max sub = " << max_sub(data, len);
}

