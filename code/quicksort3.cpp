//再一次忘记partition的返回值！！！！
#include<iostream>
using namespace std;

int A[] = {13,19,9,5,12,8,7,4,21,2,6,11};
int len = sizeof(A)/sizeof(int);

int partition(int A[],int l, int r)
{
    int x = A[r],i,j;
    for(i=l,j=l;j<r;++j)
    {
        if(A[j] <= x)
        {
            swap(A[i++],A[j]);
        }
    }
    swap(A[i],A[r]);
    return i;
}
void quicksort(int A[],int l,int r)
{
    int q;
    if(l<r)
    {
        q=partition(A,l,r);
        quicksort(A,l,q-1);
        quicksort(A,q+1,r);
    }
}

int main()
{
    for(int i = 0; i< len;++i)
        cout << A[i] << " ";
    cout << endl;
    quicksort(A,0,len-1);
    for(int i = 0; i< len;++i)
        cout << A[i] << " ";
    cout << endl;
}
