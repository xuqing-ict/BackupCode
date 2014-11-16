
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> interval;
struct point
{
    int val;
    bool is_start; //the start node or not??
    int cur_end;
    point(int _val=0, bool _b=false, int _end=-1):val(_val),is_start(_b),cur_end(_end){}
};

//ascend
struct cmp
{
    bool operator()(const point &lhs, const point &rhs)
    {
        if(lhs.val != rhs.val)
        {
            return lhs.val < rhs.val;
        }
        else
        {
            return lhs.is_start > rhs.is_start;
        }
    }
};

int main()
{
    const int N = 5;
    interval intervals[N] = {make_pair(1,3),make_pair(2,5),make_pair(4,7),make_pair(6,9),make_pair(8,10)};
    vector<interval> ret;
    int cur = 0; //record the maximum finish time of selected intervals
    for(int i=0; i<N; ++i)
    {
        if(intervals[i].first >= cur)
        {
            ret.push_back(intervals[i]);
            cur = intervals[i].second;
        }
    }
    for(auto a:ret)
    {
        cout << "[" << a.first << "," << a.second << "]" << endl;
    }

    //method 2: reverse thinking
    vector<interval> ret2;
    cur = INT_MAX;
    for(int i=N-1;i>=0;--i)
    {
        if(intervals[i].second < cur)
        {
            ret2.push_back(intervals[i]);
            cur = intervals[i].first;
        }
    }
    for(auto a:ret2)
    {
        cout << "[" << a.first << "," << a.second << "]" << endl;
    }

    vector<interval> pairs = {make_pair(1,10),make_pair(12,16),make_pair(9,17),make_pair(1,8)};
    vector<point> nodes;
    for(int i=0;i<pairs.size();++i)
    {
        nodes.push_back(point(pairs[i].first,true,pairs[i].second));
        nodes.push_back(point(pairs[i].second,false,-1));
    }
    sort(nodes.begin(), nodes.end(), cmp());
    cout << "after sorting..." << endl;
    for(int i=0; i<nodes.size();++i)
        cout << nodes[i].val << "\t";
    cout << endl;

    return 0;
}
