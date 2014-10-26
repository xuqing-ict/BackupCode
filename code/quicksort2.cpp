//������Ҫ����ĸl��Ϊ����������Ϊ��������1�ı�ʾ����һģһ��
//�ڵ��ú���ʱ��ע��������ұ߽����⣬��[0 len-1 ]!!!
#include<iostream>
using namespace std;
int A[] = {13,19,9,5,12,8,7,4,21,2,6,11};
int len = sizeof(A)/sizeof(int);

int partition(int A[], int l, int r)
{
    int x = A[r];
    int i , j ;
    for(i = l,j = l; j < r; ++j)
    {
        if(A[j] <= x)
        {
            swap(A[i++],A[j]);
        }
    }
    swap(A[i],A[r]);
    cout << "x = " << x << endl;
    for(int i = 0 ; i < len ; ++i)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    return i ;
}
void quicksort(int A[], int l, int r)
{
    int q = 0;
    if(l<r)
    {
        q = partition(A,l,r);
        quicksort(A,l,q-1);
        quicksort(A,q+1,r);
    }
}
int main()
{
    for(int i = 0 ; i < len ; ++i)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    quicksort(A,0,len-1);
    cout << "sort result... " << endl;
    for(int i = 0 ; i < len ; ++i)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    return 0;
}
