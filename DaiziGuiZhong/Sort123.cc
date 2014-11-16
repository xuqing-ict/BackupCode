/**
 * @file Sort123.cc
 * @brief
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-18
 */
/*排序只有1，2，3三个元素的数组，不能统计1，2，3的个数。*/
#include <bits/stdc++.h>
using namespace std;

/*
void sort123(int *A, const int n)
{
    if(n < 2) return;

    int p1 = 0,p2=0,p3=n-1;
    for( ; p2 <= p3; ++p2)
    {
        if(A[p2] == 1)
        {
            swap(A[p1++], A[p2]);
        }
        else if(A[p2] == 3)
        {
            swap(A[p2],A[p3]);
            --p2;
            --p3;
        }
    }
}
*/


void sort123(int *A, const int n)
{
    if(A == nullptr || n < 2) return;
    int p1=0,p2=n-1;
    int  k = 0;
    while(k <= p2)
    {
        if(A[k] == 1) {swap(A[k++],A[p1++]);}
        else if(A[k] == 3){swap(A[k],A[p2--]);}
        else ++k;
    }
}
int main(void)
{
    srand(time(NULL));
    const int n = rand()%1000;
    int *A = new int[n];
    for(int i=0;i<n;++i)
        A[i] =  rand()%3+1;
    copy(A,A+n,ostream_iterator<int>(cout,"\t"));
    cout << endl;
    sort123(A,n);
    copy(A,A+n,ostream_iterator<int>(cout,"\t"));
    cout << endl;
    for(int i=0;i+1<n;++i)
    {
        if(A[i+1] < A[i])
        {
            cout << "error!!!" << endl;
            exit(1);
        }
    }
    delete [] A;
    return 0;
}
