#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <assert.h>

using namespace std;

static double helper(const int A[], int m, const int B[], int n , int k)
{

    if( m > n ) return helper(B,n,A,m,k);

    if( m == 0 ) return B[k-1];
    if( n == 0 ) return A[k-1];

    if( k == 1) return min(A[0],B[0]);

    int pa = k/2;
    if( m <= k/2) pa = m;
    int pb = k - pa;

    if(A[pa-1] == B[pb-1])
    {
        return A[pa-1];
    }
    else if(A[pa-1] > B[pb-1])
    {
        return helper(A, pa, B+pb, n-pb,k-pb);
    }
    else
    {
        return helper(A+pa, m-pa, B, pb, k-pa);
    }
}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        int ret ;
        if( ( m+n ) & 0x01 )
            ret = helper(A,m,B,n,(m+n)/2+1);
        else
            ret = (helper(A,m,B,n,(m+n)/2) + helper(A,m,B,n,(m+n)/2+1))/2;

        return ret;
    }
int main()
{
    int A[] = {1,2,3};
    int B[] = {2,3};
    cout << findMedianSortedArrays(A,0,B,2) << endl;


    return 0;
}
