/**
 * @file shuffle.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-11
 */
//完美洗牌算法
#include <bits/stdc++.h>
using namespace std;


void shuffle(int *A, int n)
{
    if(n == 1) 
    {
        //swap(A[1],A[2]);
        int t = A[1]; A[1]=A[2];A[2]=t;
        return;
    }
    int n2 = n*2, n3 = n/2;
    if(n & 1) //odd
    {
        int t = A[n];
        for(int i=n+1;i<=n2;++i)
        {
            A[i-1]=A[i];
        }
        A[n2] = t;
        --n;
    }
    //even now
    for(int i=n3+1; i <= n;++i)
    {
        //swap(A[i],A[i+n3]);
        int t = A[i]; A[i]=A[i+n3];A[i+n3]=t;
    }
    shuffle(A,n3);
    shuffle(A+n,n3);
}

int main(void)
{
    int A[] = {0,1,2,3,4,5,6,7,8};
    int n = sizeof(A)/sizeof(int);
    for(int i=1;i<n;++i)
        cout << A[i] << "\t";
    cout << endl;
    shuffle(A,n/2);
    for(int i=1;i<n;++i)
        cout << A[i] << "\t";
    cout << endl;

    return 0;
}
