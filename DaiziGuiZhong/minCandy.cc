/**
 * @file Candy.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

#include <limits.h>

using namespace std;

int minCandy(const vector<int> &A)
{
    const int n = A.size();
    if(n < 2) return n; 
    vector<int> l(n,0),r(n,0);
    l[0]=1;
    for(int i=1;i<n;++i)
    {
        if(A[i]>A[i-1]) l[i] = l[i-1]+1;
        else l[i]=1;
    }
    r[n-1]=1;
    for(int i=n-2;i>=0;--i)
    {
        if(A[i] > A[i+1])r[i] = r[i+1]+1;
        else r[i]=1;
    }

    int ret=0;
    for(int i=0;i<n;++i)ret+=max(l[i],r[i]);
    return ret;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> A;
    A.resize(n);
    for(int  i=0;i<n;++i) cin >> A[i];
    cout << "ans : " << minCandy(A) << endl;
    return 0 ;
}
