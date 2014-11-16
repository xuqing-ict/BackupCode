#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    int idx;
    int offset;
    node(int _val = 0 , int _idx = -1, int _offset = -1):val(_val), idx(_idx),offset(_offset){}
};

struct cmp:public binary_function<bool,const node &, const node &>
{
public:
    bool operator()(const node &lhs, const node &rhs)
    {
        return lhs.val > rhs.val;
    }
};

typedef pair<int,int> P;

P minInteval(const vector<vector<int> > &A)
{
    const int m  = A.size();
    if(m < 2) return P(0,0);

    vector<int> capa;
    for(int i=0;i<m;++i) capa.push_back(A[i].size());

    priority_queue<node,vector<node> ,cmp> pq;
    int curMax = INT_MIN;
    for(int i=0; i < m;++i )
    {
        pq.push(node(A[i][0],i,0));
        curMax = max(curMax,A[i][0]);
    }
    int ans = curMax - pq.top().val;
    int l = pq.top().val, r = curMax;
    while(1)
    {
        node cur = pq.top();pq.pop();
        int val = cur.val, idx = cur.idx, off = cur.offset;
        if(curMax - val < ans)
        {
            ans = curMax-val;
            l = val;
            r = curMax;
        }
        if(off >= capa[idx]-1) return P(l,r);
        int next = A[idx][off+1];
        if(next > curMax) curMax = next;
        node tmp(next,idx,off+1);
        pq.push(tmp);
    }
    return P(l,r);
}

int main(void)
{
    vector<vector<int> > A = {{4, 10, 15, 24, 26},{0, 9, 10, 20},{5, 10, 18, 30}};
    P ret = minInteval(A);
    cout << ret.first << " " << ret.second << endl;
    return 0;
}
