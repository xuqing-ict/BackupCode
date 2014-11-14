/**
 * @file Jiuduizhizuida.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-14
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

void minSub(const vector<int> &A, vector<int> &minL, vector<int> &maxL, vector<int> &minR, vector<int> &maxR)
{
    const int n = A.size();
    
    minL[0] = A[0];
    maxL[0] = A[0];

    //get the minL and maxL first
    int min_tmp = A[0], max_tmp = A[0];
    for(int i=1;i<n;++i)
    {
        //A[0...i];
        if(min_tmp > 0 ) min_tmp = 0;
        min_tmp += A[i];
        minL[i] = min(minL[i-1],min_tmp);
        if(max_tmp < 0 ) max_tmp = 0;
        max_tmp += A[i];
        maxL[i] = max(maxL[i-1],max_tmp);
    }
    //get the minR and maxR 
    minR[n-1]=A[n-1],maxR[n-1]=A[n-1];
    min_tmp = A[n-1], max_tmp = A[n-1];
    for(int i=n-2;i>=0;--i)
    {
        //A[0...i];
        if(min_tmp > 0 ) min_tmp = 0;
        min_tmp += A[i];
        minR[i] = min(minR[i+1],min_tmp);
        if(max_tmp < 0 ) max_tmp = 0;
        max_tmp += A[i];
        maxR[i] = max(maxR[i+1],max_tmp);
    }
}
    
//minL[i] :the minimum subarray of A[0...i].
int diff(const vector<int> &A)
{
    const int n = A.size();
    if(n < 2) return 0; //illegal
    vector<int> minL(n,0),maxL(n,0),minR(n,0),maxR(n,0);
    minSub(A,minL,minR,maxL,maxR);
    int ret = INT_MIN;
    for(int i=1;i<n;++i)
    {
       //cut [0...i-1] and [i..n-1] 
        int s1 = abs(minL[i-1]-maxR[i]);
        int s2 = abs(maxL[i-1]-minR[i]);
        ret = max(ret,max(s1,s2));
    }
    return ret;
}

int main(void)
{
 // vector<int> A = {2,-1,-2,1,-4,2,8};
  vector<int> A = {-1,-1,1,2,-1,-2};
  cout << diff(A) << endl;
  return 0;
}
