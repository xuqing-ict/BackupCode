#include <bits/stdc++.h>
using namespace std;

//[left,right]
int partition(int *A, int left, int right)
{
    int pivot=A[right];
    int i=left;
    for(int k=left;k<right;++k)
        if(A[k]<pivot)swap(A[k],A[i++]);
    swap(A[right],A[i]);
    return i;
}
//A[0...k-2] k-1 [k+2,n]
void getKMin(int *A, int n, int k)
{
    if(k == 0 || A == NULL || n <= 0 ) return;
    int left=0,right=n-1;

    int index = partition(A,left,right);

    while(index != k-1)
    {
        if(index > k-1)
        {
            right = index-1;
            index = partition(A,left,right);
        }
        else
        {
            left = index+1;
            index = partition(A,left,right);
        }
    }
    sort(A,A+k);
       for(int i=0;i<k-1;i++){
            printf("%d ",A[i]);
        }
        printf("%d\n",A[k-1]);
}

int main(void)
{
    int N,k;
    while(scanf("%d %d",&N,&k) != EOF)
    {
        int *A = new int[N];
        for(int i=0;i<N;++i)
            scanf("%d",&A[i]);
        getKMin(A,N,k);
        delete [] A;
    }
    return 0;
}
