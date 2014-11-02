/**
 * @file numPair.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-01
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iterator>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;

ostream_iterator<double> out(cout, " ");

int numPair(const vector<int> &A, const vector<int> &B)
{
    const int m = A.size(), n = B.size();
    if (m == 0  || n == 0) return 0;
    vector<double> tA (m,0), tB(n,0);
    for(int i=0;i<m;++i)
        tA[i] = log(A[i])/A[i];
    for(int i=0;i<n;++i)
        tB[i] = log(B[i])/B[i];
    sort(tA.begin(),tA.end());
    sort(tB.begin(),tB.end());

    //count
    int ret = 0;
    for(auto a: tA)
    {
        auto it = upper_bound(tB.begin(),tB.end(),a);
        ret += (it-tB.begin());
    }
    return ret;
}


int main(void)
{
    vector<int> A = {3,1,2,4,5}, B = {6,8,10,9,7};
    for(auto a: A)
        if(a <= 0) cerr << "illegal..." << endl;
    for(auto b: B)
        if(b <= 0) cerr << "illegal..." << endl;

    cout << numPair(A,B) << endl;
    return 0 ;
}
