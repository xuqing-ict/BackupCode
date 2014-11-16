//此处使用的归并排序是采用的不使用哨兵元素的形式。
//如果i < j and A[i] > 3*A[j]时才算做是逆序数。
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

    i = j = 0;
	while(( i < lLen) && (j < rLen))
    {
        if (L[i] > (3*R[j]))
        {
            RC += ((right-left)/2-i+1);
            ++j;
        }
        else ++i;
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
    int len;
    int A[100];
    while(cin >> len) {
        for(int i = 0; i < len; ++i) {
            cin >> A[i];
        }
        cout <<	 mergeSort(A,0,len-1) << endl;
    }

	return 0;
}
