/**
 * @file mergeSortedArray.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-14
 */

//merge two sorted array in O(1) space complexity

#include <bits/stdc++.h>
using namespace std;

//[first,mid) and [mid,last)
void merge(int *A, const int left, int mid, const int right)
{
    assert(A!=nullptr);

    for(int i=left;i<mid;++i)
    {
        if(A[i] > A[mid])
        {
            swap(A[i],A[mid]);
            int tmp=A[mid];
            int k=mid+1;
            while(k<right && A[k]<tmp){A[k-1]=A[k];++k;}
            A[k-1]=tmp;
        }
    }
}

//merge sorted arrat version 2 (O(n*logn))
void merge2(int *A, const int left, const int mid, const int right)
{
    assert(A!=nullptr);
    for(int i=mid;i<right;++i)
    {
        if(A[i] > A[left])
        {
            auto pos=upper_bound(A+left,A+mid,A[i]);
            if(pos==A+mid) break;
            swap(*pos,A[i]);
            int tmp=A[pos];
            int k=mid+1;
            while(k<right&& A[k]<tmp) {A[k-1]=A[k];++k;}
            A[k-1]=tmp;
        }
    }
}

int main(void)
{
    
    srand(time(NULL));
    int n = rand()%20+100;
    int *A=new int[n];
    for(int i=0;i<n;++i)
        A[i]=rand()%1000;
    sort(A,A+(n/2));
    sort(A+(n/2),A+n);

   
  //  int A[] = {1,3,2,4};
    //int n = sizeof(A)/sizeof(int);
    for(int i=0; i<n;++i)
        cout << A[i] << "\t";
    cout << endl;
    merge2(A,0,n/2,n);
    for(int i=0; i<n;++i)
        cout << A[i] << "\t";
    cout << endl;

    for(int i=0; i<n-1;++i)
        assert(A[i+1]>=A[i]);

    delete A;
    return 0;
}

