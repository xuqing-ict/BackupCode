//给定数组A，找到A的一个子数组使得该子数组的和最接近于0
//注意绝对值！！！


#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;


int partition(int A[], int left, int right)
{
	int pivot = A[right];
	int i,j;
	
	for(i = j =  left ; i < right; ++i)
	{
		if (A[i] < pivot)swap(A[j++],A[i]);
	}
	swap(A[j],A[right]);
	return j;
}


void quickSort(int A[], int left, int right)
{
	cout << "enter quickSort"<< endl;
	int i;
	if (left < right)
	{
		i = partition(A, left,right);
		quickSort(A,left,i-1);
		quickSort(A,i+1,right);
	}
}
int main()
{
	int A[] = {-2,4,1,-3};
	int len = sizeof(A)/sizeof(int);
	int *sum = new int[len];
	
	sum[0] = A[0];
	
	for(int i = 1; i < len;++i)
	{
		sum[i] = sum[i-1] + A[i];
	}
	
	cout << "quickSort before " << endl;
	for(int i = 0 ; i < len; ++i)
		cout << sum[i] << " ";
	cout << endl;
	
	quickSort(sum,0,len-1);
	
	cout << "quickSort after " << endl;
	for(int i = 0 ; i < len; ++i)
		cout << sum[i] << " ";
	cout << endl;

	for(int i = 0; i < len;++i)
		sum[i] = abs(sum[i]);
	int minimum = *(min_element(sum,sum+len));

	cout << "find single minimum =  " << minimum << endl;
	
	for(int i  = 0 ; i < len; i++)
	{

	}
	cout << "minimum = " << minimum << endl;
	delete [] sum;


}
