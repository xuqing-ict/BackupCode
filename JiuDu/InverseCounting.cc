#include <bits/stdc++.h>
using namespace std;

//merge [left,mid] and [mid+1,right]
long long Merge(int *A, int left, int mid, int right)
{
    int *tmp = new int[right-left+1];
    int i=left,j=mid+1,k=0;
    long long ret=0 ; //inverse counting
    while(i<=mid && j<=right)
    {
        if(A[i] <= A[j]) tmp[k++] = A[i++];
        else
        {
            ret += (mid-i+1); //应该先赋值，再移动j
            tmp[k++] = A[j++];
        }
    }
    //left is not end...
    while(i <= mid)
    {
        tmp[k++]=A[i++];
    }
    while(j <= right)tmp[k++]=A[j++];

    for(int k=0;k<right-left+1;++k)
        A[left+k] = tmp[k];
    delete [] tmp;
    return ret;
}

long long InverseCounting(int *A, int left, int right)
{
    if(left >= right) return 0; //递归的退出条件
    int mid = left + (right-left)/2;
    long long  L = InverseCounting(A,left,mid);
    long long R = InverseCounting(A,mid+1,right);
    long long M = Merge(A,left,mid,right);
    return L+R+M;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int *A = new int[n];
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        cout << InverseCounting(A,0,n-1) << endl;
        delete [] A;
    }
    return 0;
}
