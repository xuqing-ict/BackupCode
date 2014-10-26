//此处使用的归并排序是采用的不使用哨兵元素的形式。
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
using namespace std;

int merge(int A[], int left, int mid, int right)
{
	int RC = 0; 
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
			RC += ((right-left)/2-i+1);
			//此处的right和left指的是当前处理的数组的right和left，
			//很直观的讲，此处应该加上的是|L|-i，而L的长度就是(right-left)/2+1
			//注意！！左边的长度为|L| = mid-left+1 = (left+(right-left)/2)-left+1
			//而此时处理的元素的偏移量为i，即该元素前面的元素个数为i，则用|L|-i = (right-left)/2+1-i即为所求。
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
	return RC;
}



int mergeSort(int A[], int left, int right)
{
	int mid;
	int RCL = 0, RCR = 0 , RC = 0 ;
	if(left < right)
	{
		mid = left + (right-left)/2;
		RCL = mergeSort(A,left,mid);
		RCR = mergeSort(A,mid+1,right);
		RC = merge(A,left,mid,right);
	}
	return (RCL + RCR + RC);
}



int main()
{
	srand(time(NULL));
	int len = rand()%10;
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
	cout <<	mergeSort(A,0,len-1) << endl;
	for(int i = 0; i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	delete [] A;
	return 0;
}
