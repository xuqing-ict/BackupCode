
#include<bits/stdc++.h>
using namespace std;

ostream_iterator<int> out (cout, "\t");
int part(int A[], int left, int right)
{
    int pivot = A[right];
    int i = left, k = left;
    while(k <= right)
    {
        if(A[k] <= pivot) swap(A[k],A[i++]);
        k++;
    }
    return i-1;
}
void quickSort(int A[], int left, int right)
{
    if(left < right)
    {
        int i = part(A,left, right);
        quickSort(A,left,i-1);
        quickSort(A,i+1, right);
    }
}

int main(void)
{
    int A[] = {2,1};
    int n = sizeof(A)/sizeof(int);
    quickSort(A,0,n-1);
    copy(A,A+n,out);
    cout << endl;
    return 0;
}
