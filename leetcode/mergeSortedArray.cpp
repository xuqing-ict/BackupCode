#include<iostream>
using namespace std;

void merge(int A[], int m, int B[], int n) 
{
//	if(n == 0)return;
	int i = m-1;
	int j = n-1;
	int k = m+n-1;
	cout << i << " " << j << " " << k << endl;
	while(i >= 0 && j >= 0)
	{
		if(A[i] >= B[j]) 
		{
			cout << A[i] << " ";
			A[k] = A[i];
			k--;i--;
		}
		else
		{
			cout << B[j] << " ";
			A[k] = B[j];
			k--;j--;
		}
	}
	while(j >= 0 && k >= 0)
	{
		cout << B[j] << " ";
		A[k] = B[j];
		k--;j--;
	}
	cout << endl;
}
int main()
{
	int A[10] = {2,4,6,8};
	for(int i =0 ;i < 8; ++i)
		cout << A[i] << " ";
	cout << endl;
	int B[4] = {1,3,5,7};
	merge(A,4,B,4);
	for(int i =0 ;i < 8; ++i)
		cout << A[i] << " ";
	cout << endl;
}
