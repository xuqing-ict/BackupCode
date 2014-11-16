#include <bits/stdc++.h>
using namespace std;

int Lower_bound(int *A, const int n, const int target)
{
    if(A == nullptr || n <= 0) return -1;
    int left=0,right=n-1,mid=-1;
    while(left <= right)
    {
        mid = left+(right-left)/2;
        if(A[mid] < target) left = mid+1;
        else right=mid-1;
    }
    return left;
}
int Upper_bound(int *A, const int n, const int target)
{
    if(A == nullptr || n <=0 ) return 0;
    int left=0,right=n-1,mid=-1;
    while(left <= right)
    {
        mid = left + (right-left)/2;
        if(A[mid] <= target) left=mid+1;
        else right = mid-1;
    }
    return left;
}
int main(void)
{
    /*
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int *A = new int[n];
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        int k,target;
        scanf("%d",&k);
        for(int i=0;i<k;++i)
        {
            scanf("%d",&target);
            int left = Lower_bound(A,n,target);
            int right = Upper_bound(A,n,target);
            cout << right-left << endl;
        }
        delete [] A;
    }
    */
    int A[] = {1,2,3,3,3,3,5,6};
    int n = sizeof(A)/sizeof(int);
    cout << Lower_bound(A,n,4) << endl;
    cout << Upper_bound(A,n,4) << endl;
    return 0;
}
