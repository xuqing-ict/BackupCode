/**
 * @file mergeKSortedArray.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-17
 */
//合并N个有序数组
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> P;
// <value, row, col>

struct mycompare : public binary_function<const P, const P, bool>
{
    bool operator()(const P &lhs, const P &rhs)
    {
        return get<0>(lhs) > get<0>(rhs);
    }
};

vector<int> mergeKSortedArray(vector<vector<int> > &A)
{
    const int n  = A.size();
    if(n == 0) return vector<int>();
    if(n < 2) return A[0];

    priority_queue<P,vector<P>,mycompare> pq;

    for(int i = 0; i < n; ++i)
    {
        if(A[i].empty()) continue;
        pq.push(make_tuple(A[i][0], i, 0));
    }
    
    vector<int> ret;

    while(!pq.empty())
    {
        P elem = pq.top(); pq.pop();
        int row = get<1>(elem);
        int col = get<2>(elem);
        ret.push_back(get<0>(elem));
        if(col+1 < A[row].size())
        {
            pq.push(make_tuple(A[row][col+1], row, col+1));
        }
    }
    return ret;
}

int main(void)
{
    srand(time(NULL));
    const int N = rand()%10;
    vector<vector<int> > A;
    for(int i=0;i<N;++i)
    {
        int M = rand()%10;
        A.push_back(vector<int>(M,0));
        for(int j=0;j<M;++j)
        {
            A[i][j] = rand()%100;
        }
    }
    cout << "here ... " << endl;
    for(int i=0; i<N; ++i)
        sort(A[i].begin(), A[i].end());

    /*
    vector<vector<int> > A;
    vector<int> a1 = {1,3,5};
    vector<int> a2 = {2,4,6};
    A.push_back(a1);
    A.push_back(a2);

    */
    vector<int> ret = mergeKSortedArray(A);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
