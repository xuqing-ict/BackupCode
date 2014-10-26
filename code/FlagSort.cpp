#include<iostream>
using namespace std;
void sortFlag(int A[], int len)
{
	int i = 0;
	int j = len-1;
	int k = 0;
	while(k <= j)
	{
		if (A[k] == 0)
		{
			swap(A[k++],A[i++]);
		}
		else if (A[k] == 2)
		{
			swap(A[k],A[j--]);
		}
		else
		{
			k++;
		}
	}
}
int main()
{
	int A[] = {1,2,0,2,0,1,2,0,2,0,1};
	int len = sizeof(A)/sizeof(int);
	for(int i = 0; i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;	
	sortFlag(A,len);
	for(int i = 0; i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;

}
