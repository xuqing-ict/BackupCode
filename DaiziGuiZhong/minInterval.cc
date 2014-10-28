/**
 * @file minInterval.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-28
 */
/*
k个有序的数组，找到最小的区间范围使得这k个数组中，每个数组至少有一个数字在这个区间范围内。比如：
数组1：[4, 10, 15, 24, 26]
数组2：[0, 9, 12, 20]
数组3：[5, 18, 22, 30]
最小的区间是[20, 24]，这个区间包含了数组1中的24，数组2中的20，数组3中的22
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <queue>
using namespace std;
typedef pair<int,int> P;

P minInterval(const vector<vector<int> > &A)
{
    const int m = A.size();
    if(m < 2) return P(0,0);
    const int n = A[0].size();
    priority_queue<,vector<int>, greater<int> > pq;
    int curMax = INT_MIN;
    for(int i=0;i<m;++i)
    {
        pq.push(A[i][0]);
        curMax = max(curMax,A[i][0]);
    }
    P ret(pq.top(),maxVal);
    while(1)
    {
    }
}

int main(void)
{
    vector<vector<int> > A;
    cin >> m >> n;
    A.resize(m*n);
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin >> A[i][j];
    for(int i=0;i<m;++i)
        sort(A[i].begin(),A[i].end());

    P p = minInterval(A);
    cout << p.first << " " << p.second << endl;
    return 0;
}

