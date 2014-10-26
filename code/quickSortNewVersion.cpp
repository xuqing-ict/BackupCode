//此版本也能处理元素全相同的情况
#include<iostream>
using namespace std;

void quickSort(int A[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right-left)/2;
	int pivot = A[mid];
	swap(A[mid],A[right]);

	cout << "pivot = " << pivot << endl;
	int i = left, j = right;
	while(i<=j)
	{
		while(A[i] < pivot){++i; }
		while(i <= j && A[j] >= pivot){--j ;}
		if (i<=j)
		{
			swap(A[i],A[j]);
			i++;j--;
		}
	}
	swap(A[i], A[right]);
	
	quickSort(A, left,j);
	quickSort(A,i+1,right);
}


void shellSort(int A[], int n)
{
	for(int gap = n/2 ; gap > 0; gap = gap/2)
	{
		for(int k = gap ; k < n ; ++k)
		{
			if (A[k] < A[k-gap])
			{
				int x = A[k];
				int i = k - gap;
				while( i >= 0 && A[i] > x)
				{
					A[i+gap] = A[i];
					i -= gap;
				}
				A[i+gap] = x;
			}
		}
	}
}

int main()
{
	int A[] = {-2,1};
	int len = sizeof(A)/sizeof(int);
	for(int i=0;i<len;++i)
		cout << A[i] << " ";
	cout << endl;
	
	quickSort(A,0,len-1);
	//shellSort(A,len);

	for(int i=0;i<len;++i)
		cout << A[i] << " ";
	cout << endl;
}
