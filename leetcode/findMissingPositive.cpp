#include <bits/stdc++.h>
using namespace std;

ostream_iterator<int> out(cout,"\t");

void bucket_sort(int A[], int n)
{
    for(int i = 0 ; i < n ; ++i)
    {
        while(A[i] != i+1)
        {
            if(A[i] <0 || A[i] > n || A[i] == A[A[i]-1])
                break;
            swap(A[i],A[A[i]-1]);
        }
    }
}
int firstMissingPositive(int A[], int n)
{
    bucket_sort(A,n);
    copy(A,A+n,out);
    for(int i = 0 ;i < n; ++i)
    {
        if(A[i] != i +1)
            return i+1;
    }
    return n+1;
}

int main()
{
    int A[] = {3,4,-1,1};
    int n = 4;
    cout << firstMissingPositive(A,n) << endl;
    return 0;
}


