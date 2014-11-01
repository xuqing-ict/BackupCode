/**
 * @file cutMaxStrand.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-31
 */

//cut max strand
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;

int maxCutLen(const int n)
{
    if(n <= 0 )return 0;
    if(n == 1) return 0; //illegal input
    vector<int> f(n+1,0); //f[i]: 长度为i的绳子至少切一刀的最长的长度。
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i=3;i<=n;++i) //length
        for(int j=1;j<=i/2;++j) // enumerate the length of the first segment
            f[i] = max(f[i],max(j*f[i-j], (i-j)*j)); // (j-i)*j : cut once

    for(auto a: f) cout << a << " ";cout << endl;
    return f[n];
}

int main(void)
{
    int n ; 
    cin >> n;
    cout << "ans : " << maxCutLen(n) << endl;
    return 0 ;
}
