/**
 * @file wangwozhichengji.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-15
 */

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

vector<int> compute(const vector<int> &A)
{
    const int n = A.size();
    vector<int> B(n,1);
    B[0] = A[0];
    for(int i=1;i<n-1;++i)
        B[i] = B[i-1]*A[i];
    B[n-1] = B[n-2];
    int c = A[n-1];
    cout << "subArr : " ;
    for(auto b:B)cout << b << " "; cout << endl;
    for(int i=n-2;i>=1;--i)
    {
        B[i] = B[i-1]*c;
        c *= A[i];
    }
    B[0] = c;
    return B;
}

int main(void)
{
    vector<int> A = {2,3,1,4,2};
    vector<int> B = compute(A);
    for(auto a: B) cout << a << " ";
    cout << endl;
    return 0 ;
}
