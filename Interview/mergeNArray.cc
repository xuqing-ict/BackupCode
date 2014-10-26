/**
 * @file mergeNArray.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-10
 */
/*一个 m * n 的数组，每一行都有序。每一行都选择一个元素，这样就得到 m 个元素，它们的 最大值和最小值的差，越小越好。
 * 问最优值是？*/
#include <bits/stdc++.h>
using namespace std;

int answer(const vector<vector<int> > &A)
{
    const int m = A.size();
    if(m == 0) return 0;
    const int n = A[0].size();
    for(int i=0;i<m;++i)
    {
    }
}

typedef tuple<int,int,int> Triple;
struct cmp:public binary_function<bool, const Triple &, const Triple &>
{
    bool operator() (const Triple &lhs, const Triple &rhs)
    {
        return get<2>(lhs) > get<2>(rhs);
    }
};

int minStd(const vector<vector<int> > & A)
{
    const int m =  A.size();
    if(m == 0) return 0;
    const int  n = A[0].size();
    priority_queue<Triple,vector<Triple>,cmp> pq;
    int ret_min = INT_MAX, ret_max = INT_MIN;
    int cur_min = INT_MAX, cur_max = INT_MIN;
    int ret = INT_MAX;
    for(int i=0;i<m;++i)
    {
        if(cur_min > A[i][0] ) cur_min = A[i][0];
        if(cur_max < A[i][0]) cur_max = A[i][0];
        pq.push(make_tuple(i,0,A[i][0]));
    }
    ret = cur_max-cur_min;
    ret_max = cur_max;
    ret_min = cur_min;

    while(!pq.empty())
    {
        Triple t = pq.top();
        cur_min = get<2>(t);
        int i = get<0>(t);
        int j = get<1>(t);
        if(cur_max - cur_min < ret)
        {
            ret_max = cur_max;
            ret_min = cur_min;
            ret = ret_max - ret_min;
        }
        if(j == n-1) break; //last element
        pq.pop();
        ++j;
        if(A[i][j] > cur_max) cur_max= A[i][j];
        pq.push(Triple(i,j,A[i][j]));
    }
    cout << "result : " << ret_min << "\t" << ret_max << "\t" << ret << endl;
    return ret;
}
int main(void)
{
    srand(time(nullptr));
    int k = 100;
    while(--k)
    {
        int m = 10, n= 100;
        vector<vector<int> > A(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                A[i][j] = rand()%100;
            }
        }
        for(int i=0;i<m;++i)
            sort(A[i].begin(),A[i].end());
        for(int i=0;i<m;++i)
        {
            copy(A[i].begin(),A[i].end(),ostream_iterator<int>(cout,"\t"));
            cout << endl;
        }
        int ret1 = minStd(A);
        int ret2 = answer(A);
        assert(ret1 == ret2);

    }
    return 0;
}
