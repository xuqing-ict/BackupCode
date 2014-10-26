/**
 * @file Reorder.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-25
 */
//数组重新排序，使得奇数在左边，偶数在右边
#include <bits/stdc++.h>
using namespace std;

void reorder(int *A, int n)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        if(!(A[i]&1))//偶数
        {
            cout << "swap : " << A[i] << A[j] << endl;
            swap(A[i],A[j--]);
        }
        else
        {
            ++i;
        }
    }
}

int main(void)
{
    int A[] = {2,1,3,4,6,5,7};
    const int n = sizeof(A)/sizeof(int);
    for(int i=0;i<n;++i)cout << A[i] << "\t";
    cout << endl;
    reorder(A,n);
    for(int i=0;i<n;++i)cout << A[i] << "\t";
    return 0;
}
