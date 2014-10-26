#include <cstring>
#include <algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
const int N=10000;
int partition(int A[],int left, int right)
{
	int x = A[right];
	int i = left;
	for(int k = left ; k <= right; ++k)
	{
		if(A[k] <= x)swap(A[i++],A[k]);
	}
	return (i-1);
}
void quickSort(int A[],int left,int right)
{
	int pivot;
	if(left < right)
	{
		pivot = partition(A, left,right);
		quickSort(A,left,pivot-1);
		quickSort(A,pivot+1,right);
	}
}

void quickSort2(int A[], int left, int right)
{
	int i = left, j = right;
	int x = A[left + (right-left)/2];
	while(i<j)
	{
		while(A[i] < x)i++;
		while(A[j] > x)j--;
		if(i<j)
		{
			swap(A[i],A[j]);
			i++;j--;
		}
	}
	quickSort(A,left,j);
	quickSort(A,i,right);
}

void quickSort3(int A[], int left, int right )
{
	int x = A[left+(right-left)/2];
	int i = left,j = right,k = left;
	while(k <= j)
	{

	}
}

void Randomize(int *a, int n)
{
  for(int i=0; i<n; ++i)
    a[i] = rand() % 1000000;
}

void Test()
{
  srand(time(0));
  int *a(NULL), *b(NULL), n;
  for(int i=0; i<N; ++i)
  {
    n = rand() % 10000;
    a = new int[n];
    b = new int[n];
    Randomize(a, n);
    memcpy(b, a, sizeof(int)*n);
    quickSort2(a, 0, n-1);
    sort(b, b+n);
    for(int i=0; i<n; ++i)
    {
      if(a[i]-b[i]) 
	  {
	    cout << "error" << endl;
		break;
	  }
    }
    delete [] a;
    delete [] b;
  }
}

int main()
{
    Test();
	/*
	srand(time(0));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0; i < len; ++i)
		A[i] = rand()%20;
	for(int i=0;i<len;++i)cout<<A[i]<<" ";
	cout << endl;
	quickSort2(A,0,len-1);
	for(int i=0;i<len;++i)cout<<A[i]<<" ";
	cout << endl;
	delete [] A;

	len = rand()%20;
	int *B = new int[len];
	for(int i = 0; i < len; ++i)
		B[i] = rand()%20;
	for(int i=0;i<len;++i)cout<<B[i]<<" ";
	cout << endl;
	quickSort(B,0,len-1);
	for(int i=0;i<len;++i)cout<<B[i]<<" ";
	cout << endl;
	delete [] B;

	len = rand()%20;
	int *C = new int[len];
	for(int i = 0; i < len; ++i)
		C[i] = 10;
	for(int i=0;i<len;++i)cout<<C[i]<<" ";
	cout << endl;
	quickSort(C,0,len-1);
	for(int i=0;i<len;++i)cout<<C[i]<<" ";
	cout << endl;
	delete [] C;
	*/
	/*
	int a[]={1,3,4,2};
	quickSort2(a, 0, 3);
    for(int i=0; i<4; ++i)
	  cout << a[i] << " ";
	cout << endl;
	*/
	return 0;
}
