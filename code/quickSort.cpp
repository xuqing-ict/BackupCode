#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int A[], int l, int r)
{
	int x = A[r];
	int i,j;
	for(i=j=l;j<r;j++)
	{
		if (A[j] <= x)
		{
			swap(A[j],A[i]);
			i++;
		}
	}
	swap(A[i],A[r]);
	return i;
}
int partitionRandom(int A[], int l, int r)
{
	int k =  rand()%(r-l+1) + l;
	swap(A[k],A[r]);
	return partition(A,l,r);
}
void quickSortRandom(int A[], int l, int r)
{
	int q;
	if (l < r)
	{
		q = partitionRandom(A,l,r);
		quickSortRandom(A,l,q-1);
		quickSortRandom(A,q+1,r);
	}
}
void quickSort(int A[], int l,int r)
{
	int q;
	if (l < r)
	{
		q = partition(A,l,r);
		quickSort(A,l,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	int A[] = {2,8,7,1,3,5,6,4};
	int len = sizeof(A)/sizeof(int);
	for(int i = 0;i< len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	quickSortRandom(A,0, len-1);	
	for(int i = 0;i< len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
