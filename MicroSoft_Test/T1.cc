/**
 * @file Test.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-18
 */

//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <cstdlib>
using namespace std;

int Print(const vector<int> &A, const int M)
{
    const int n  = A.size();
    if ( M >= n)
        return 100;
    vector<int> inter(n+1,0);
    inter[0] = A[0]-1;
    for(int i=1;i<n;++i)
    {
       inter[i] = A[i]-A[i-1]-1;
    }
    inter[n] = 100 - A[n-1];
    int len = M + 1;
    int tmp=0;
    for(int i=0;i<len;++i)
        tmp += inter[i];
    tmp += M;
    int ret = tmp;
    for(int i=len;i<n+1;++i)
    {
        tmp -= inter[i-len];
        tmp += inter[i];
        if(tmp > ret) ret = tmp;
    }
    return ret;
}       

int main(void)
{
    int n;
    int N, M;
    cin >> n;
    vector<int> A;
    for(int i=0;i<n;++i)
    {
        cin >> N >> M;
        A.resize(N);
        for(int i=0;i<N;++i)
            cin >> A[i];
        cout << Print(A,M) << endl;
    }
    return 0;
}
