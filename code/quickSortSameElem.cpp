#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void quickSort(int A[], int left, int right)
{
	if (left > right)
	{
		return;
	}
	int i = left, j = right;
	int pivot = A[left+(right-left)/2];
	cout << "pivot = " << pivot << endl;
	while(i <= j)
	{
		while(A[i] < pivot) i++;
		while(A[j] > pivot) j--;
		if (i <= j)
		{
			swap(A[i],A[j]);
			i++;
			j--;
		}

	}
	quickSort(A,left,j);
	quickSort(A,i,right);
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
