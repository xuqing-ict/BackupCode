//对于归并排序的循环不变式
//只有一个元素（l==r）的时候，是不需要再继续排序了
//注意每个函数的输入数组的边界的意义
//加入哨兵元素的重要性,当一个到达哨兵元素的时候，另一组的元素不可能比哨兵元素大，因此会一直加入，当二者都到达哨兵元素时，由于循环变量k的控制，两者将不再进行比较，直接跳出循环
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAX = 100;
void merge(int A[], int left, int mid, int right)
{
	int *L = new int[mid-left+1+1];
	int *R = new int[right-mid+1];
	for(int i = 0; i < mid-left+1; ++i ) L[i] = A[left+i];
	L[mid-left+1] = MAX;
	for(int i = 0; i < right-mid; ++i ) R[i] = A[mid+1+i];
	R[right-mid] = MAX;
	int i = 0,j = 0;
	for(int  k = left ; k <= right; k++ )
	{
		if (L[i] <= R[j]) A[k] = L[i++];
		else A[k] = R[j++];
	}
	delete [] L;
	delete [] R;

}


void mergeSort(int A[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = left + (right-left)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left, mid,right);
	}
}



int main()
{
	/*
	srand(time(NULL));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0 ; i < len; ++i)
		A[i] = rand()%20;
	for(int i = 0 ; i < len; ++i)cout << A[i] << " ";
	cout << endl;
	*/
	int A[] = {6,7,5};
	int len = 3;
	mergeSort(A,0, len-1);
	for(int i = 0 ; i < len; ++i)cout << A[i] << " ";
	cout << endl;
//	delete [] A;

	return 0;
}
