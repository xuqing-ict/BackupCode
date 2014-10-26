#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<climits>
using namespace std;

int Merge(int A[], int l, int mid, int r,int &mStart, int &mEnd)
{
	int minL = INT_MAX;
	int maxR = INT_MIN;
	for(int i=l; i<=mid; ++i)
	{
		if(A[i] < minL){mStart=i;minL= A[i];}
	}
	for(int i=mid+1; i<=r; ++i)
	{
		if(A[i] > maxR){mEnd=i;maxR= A[i];}
	}
	return (maxR-minL);
}

int FindMax(int A[], int l, int r,int &left, int &right)
{
	int ret = INT_MIN, maxL, maxR, maxM ;
	int mid = 0;
	int lStart=0,lEnd=0;
	int rStart=0,rEnd=0;
	int mStart=0,mEnd = 0;

	if(l < r)
	{
		mid = l + (r-l)/2;
		maxL = FindMax(A,l,mid,lStart,lEnd);
		maxR = FindMax(A,mid+1,r,rStart,rEnd);
		maxM = Merge(A,l,mid,r,mStart,mEnd);
		ret = maxL;
		left = lStart;
		right = lEnd;
		if(maxR > ret){ret=maxR;left=rStart;right=rEnd;}
		if(maxM > ret){ret=maxM;left=mStart;right=mEnd;}
	}

	return ret;
}

int FindMax2(int A[], int l, int r, int &left, int &right)
{
	//invalid
	if(l>r)return INT_MIN;
	int ret = INT_MIN, temp= A[l];
	left = l;
	//lIndex recored the probable left 
	int lIndex = left;
	for(int i=l+1; i<=r;++i)
	{
		if(ret < A[i]-temp){ret = A[i]-temp; right=i;left=lIndex;}
		if(A[i] < temp) {lIndex=i;temp = A[i];}
	}
	return ret;
}

int main()
{
	srand(time(NULL));
	int len = rand()%10+5;
	int *A = new int[len];
	
	for(int i=0;i< len;++i)A[i]=rand()%30;

	for(int i=0;i< len;++i)cout << A[i] << " ";
	cout << endl;
	int left=0,right=0;
	cout << FindMax(A, 0,len-1,left,right) << endl;
	cout << "left = " << left << " right = " << right << endl;
	left=right=0;
	cout << FindMax2(A, 0,len-1,left,right) << endl;
	cout << "left = " << left << " right = " << right << endl;
	delete [] A;
	return 0;
}
