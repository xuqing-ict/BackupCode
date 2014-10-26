#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
	int *L = new int[mid-left+1];
	int *R = new int[right-mid];
	int lLen = mid - left + 1;
	int rLen = right - mid;
	for(int i = 0; i < lLen; ++i)
		L[i] = A[left+i];
	for(int i = 0; i < rLen; ++i)
		R[i] = A[mid+1+i];
	int i(0),j(0),k(left);
	while(( i < lLen) && (j < rLen))
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
			k++;
		}
		else
		{
			A[k] = R[j];
			j++;
			k++;
		}
	}
	assert(i <= lLen && j <= rLen);
	while(i < lLen)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while(j < rLen)
	{
		A[k] = R[j];
		k++;
		j++;
	}
	delete [] L;
	delete [] R;
}



void mergeSort(int A[], int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = left + (right-left)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,right);
	}
}



int main()
{
	srand(time(NULL));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0; i < len; ++i)
	{
		A[i] = rand()%10;
	}
	for(int i = 0; i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	mergeSort(A,0,len-1);
	for(int i = 0; i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	delete [] A;
	return 0;
}
