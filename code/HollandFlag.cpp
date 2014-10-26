#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int A[], int left, int right)
{
	int pivot = A[(left+right)/2];
	//int pivot = 1;
	cout << "pivot = " << pivot << endl;
	int i = left, j = right;
	int k = left;
	while(k <= j)
	{
		if (A[k] > pivot)
		{
			swap(A[k],A[j--]);
		}
		else if (A[k] < pivot)
		{
			swap(A[k++],A[i++]);
		}
		else
		{
			k++;
		}
	}
	return j;
	//return k-1;
	//return i;
}

void quickSort(int A[], int left, int right)
{
	if (left > right)
	{
		return;
	}
	int i;
	i = partition(A,left,right);
	quickSort(A,left,i-1);
	quickSort(A,i+1,right);
}
int main()
{
	srand(time(NULL));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0 ; i < len; ++i)
		A[i] = rand()%20;
	for(int i = 0 ; i < len; ++i)cout << A[i] << " ";
	cout << endl;
	quickSort(A,0, len-1);
	for(int i = 0 ; i < len; ++i)cout << A[i] << " ";
	cout << endl;
	delete [] A;

}
