/**
 * @file missingDigit.cc
 * @brief
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-01
 */
 /*给定一个无序的整数数组，怎么找到第一个大于0，并且不在此数组的整数。
 比如[1,2,0] 返回 3, [3,4,-1,1] 返回 2。最好能O(1)空间和O(n)时间。*/

#include <bits/stdc++.h>
using namespace std;


int missingdigit(vector<int> A)
{
    const int n = A.size();
    unordered_set<int> exist;
    for(auto a:A)exist.insert(a);
    for(int i=1;i<=(n+1);++i)
        if(exist.find(i) == exist.end())
            return i;
}

int missingdigit2(vector<int> A)
{
    const int n = A.size();
    for(int i=0;i<n;++i)
    {
        while(A[i] != i)
        {
            if(A[i] >= n || A[i] <= 0) break;
            swap(A[i],A[A[i]]);
        }
    }
    //for(auto a: A) cout << a << "\t";
    //cout << endl;
    for(int i=1;i<n;++i)
        if(A[i] != i ) return i;
    return (A[0] == n)?(n+1):A[0];
}

int main(void)
{
    int k = 0 ;
    srand(time(nullptr));
    int n;
    while(k < 10000)
    {
        n = rand()%100+10;
        vector<int> A = {4,1,2,3};
        int t1 = missingdigit(A);
        int t2 = missingdigit2(A);
        assert(t1 == t2);
        ++k;
    }

    return 0;
}
