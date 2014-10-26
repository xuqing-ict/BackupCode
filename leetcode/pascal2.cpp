#include<iostream>
#include<ctime>
#include<cstdlib>
#include<assert.h>

using namespace std;

int main()
{
	int num = 3;
	int *A = new int[num+1];
	for(int i = 0 ; i < num+1; ++i)
		A[i] = 0;
	A[0] = 1;
	for(int i = 0 ; i <= num; ++i)
	{
		for(int j = i; j >= 1; j--)
		{
			A[j] = A[j] + A[j-1];
		}
		cout << "i = " << i << " : ";
		for(int k = 0;k <= i;++k)
			cout << A[k] << " ";
		cout << endl;
	}
}
