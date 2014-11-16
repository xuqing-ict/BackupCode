#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Pair;

vector<Pair> MergeInterval(vector<Pair> &intervals)
{
    sort(intervals.begin(),intervals.end());
    const int n = intervals.size();
    if(n < 2) return intervals;
    int i=0 ;
    int left=intervals[0].first, right=intervals[0].second;
    vector<Pair> ret;
    for(int i=1; i<n; ++i)
    {
        if(right < intervals[i].first)
        {
            ret.push_back(make_pair(left, right));
            left = intervals[i].first;
            right = intervals[i].second;
        }
        else
        {
            right = max(right,intervals[i].second);
        }
    }
    ret.push_back(make_pair(left,right));
    return ret;
}

int main(void)
{
    int n;
    cin >> n;
    vector<Pair> Intervals;
    Intervals.resize(n);
    int left, right;
    for(int i=0; i<n ;++i)
    {
        cin >> left;
        cin >> right;
        Intervals[i] = make_pair(left, right);
    }
    vector<Pair> ret = MergeInterval(Intervals);
    for(int i=0; i< ret.size();++i)
        cout<< ret[i].first << " " << ret[i].second << endl;
    return 0;
}
