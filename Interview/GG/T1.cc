/**
 * @file kthNum.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-16
 */
//k-th largest element in array
#include <bits/stdc++.h>
using namespace std;

int partition(int *A, const int left, const int right)
{
    int pivot = A[right];
    int i=left;
    for(int k=left;k<right;++k)
    {
        if(A[k] < pivot) swap(A[i++], A[k]);
    }
    swap(A[i],A[right]);
    return i;
}

void kthNum(int *A, const int n, int k)
{
    if(A == NULL ||  k <= 0 || k > n)
    {
        cout << "illegal input..." << endl;
        return;
    }

    int index=0,left=0,right=n-1;
    --k;
    while(index != k)
    {
        index = partition(A,left,right);
        if(index == k) return ;
        else if(index > k) right =index-1; 
        else left = index+1;
    }
    return;
}

ostream_iterator<int> out(cout,"\t");

int main(void)
{
    srand(time(NULL));
    int n, k;
    while(scanf("%d %d",&n,&k) != EOF)
    {
        int *A = new int[n];
        for(int i=0;i<n;++i) 
            scanf("%d", &A[i]);
        kthNum(A,n,k);
	sort(A,A+k);
        for(int i=0;i<k;++i)
            cout << A[i] << " ";
        cout << endl;
        delete [] A;
        A = NULL;
    }
    return 0;
}
