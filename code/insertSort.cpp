#include<iostream>
#include<cstdlib>

using namespace std;

void insertSort(int A[], int len)
{
	int key,j;
	for(int i = 2; i < len ; ++i)
	{
		key = A[i];
		j = i-1;
		while(j >= 0 && A[j] > key)
		{
			A[j+1] = A[j];
		}
		A[j+1] = key;
	}
}
int main()
{
	srand(time(NULL));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0 ; i < len ; ++i)
		A[i] =  rand()%20;
	for(int i = 0 ; i < len ; ++i)
		cout << A[i] << " ";
	cout << endl;
	insertSort(A,len);
	for(int i = 0 ; i < len ; ++i)
		cout << A[i] << " ";
	cout << endl;
	delete [] A;

	return 0;
}
