/**
 * @file firstMissingDigit.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-05
 */

/*给定一个无序的整数数组，怎么找到第一个大于0，并且不在此数组的整数。比如[1,2,0] 返回 3, [3,4,-1,1] 返回 2。最好能O(1)空间和O(n)时间。*/

#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
int answer(const vector<int> &A)
{
    const int n = A.size();
    unordered_set<int> exist;
    for(auto a:A) exist.insert(a);
    for(int i=1;i<n;++i)
        if(exist.find(i) == exist.end()) return i;
    return n;
}

// 原来的代码有BUG！！！竟然！！
//A[i] 保存的是 （i+1）的值！！
int firstMissingDigit(vector<int> &A) {
    const int n = A.size(); 
    for(int i=0;i<n;++i)
    {
        while(A[i] != (i+1))
        {
            //如果A[i]的范围不是[1,n-1]内部的话，那么不能直接操作!!!
            if(A[i] < 1 || A[i] >= n || A[i] == A[A[i]-1]) break;
            swap(A[i],A[A[i]-1]);
        }
    }
    for(int i=0;i<n;++i)if(A[i] != (i+1)) return (i+1);
    return n+1;
}

int main(void)
{
    
    srand(time(nullptr));
    int k = 0 ;
    vector<int> A;
    while( k < 1000) 
    {
        int n = rand()%100+10;
        A.resize(n);
        for(int i=0;i<n;++i)
            A[i] = rand()%10;
        copy(A.begin(),A.end(),ostream_iterator<int>(cout,"\t"));
        cout << endl;
        int ans = answer(A);
        int ret = firstMissingDigit(A);
        cout << "ans = " << ans << endl;
        cout << "ret = " << ret << endl;
        assert(ret == ans); 
        ++k;
    }
    /*
    vector<int> A = {2,2,2,2,2};
        copy(A.begin(),A.end(),ostream_iterator<int>(cout,"\t"));
        cout << endl;
        int ans = answer(A);
        int ret = firstMissingDigit(A);
        cout << "ans = " << ans << endl;
        cout << "ret = " << ret << endl;
        assert(ret == ans); 
        */
    return 0;
}
