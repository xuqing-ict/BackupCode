/**
 * @file 2.19.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-01
 */

#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start,end;
    Interval(int _start, int _end):start(_start),end(_end){}
};

struct cmp : public binary_function<const Interval &, const Interval &, bool>
{
    bool operator() (const Interval &lhs, const Interval &rhs)
    {
        return lhs.start < rhs.start;
    }
};

vector<Interval> Merge(vector<Interval> & intervals)
{
    const int n = intervals.size();
    if(n<2) return intervals;
    sort(intervals.begin(),intervals.end(),cmp());
    vector<Interval> ret;
    int left=intervals[0].start, right = intervals[0].end;
    for(int i=1;i<n;++i)
    {
        if(intervals[i].start <= right)
        {
            right=max(right,intervals[i].end);
        }
        else
        {
            ret.push_back(Interval(left,right));
            left = intervals[i].start;
            right = intervals[i].end;
        }
    }
    ret.push_back(Interval(left,right));
    return ret;
}
int Search(const vector<Interval> &intervals, const int x)
{
    const int  n = intervals.size();
    if(n==0)return -1;
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if (intervals[mid].end < x) left=mid+1;
        else right=mid-1;
    }
    if(intervals[left].start<= x) return left;
    return -1;
}

bool Search(const vector<Interval> &intervals, Interval &target)
{
    const int n = intervals.size();
    if(n == 0) return false;
    int idx1 = Search(intervals,target.start);
    int idx2 = Search(intervals,target.end);
    if(idx1 != -1 && idx2 != -1 && idx1==idx2) return true;
    return false;
}
int main(void)
{   
    vector<Interval> A;
    A.push_back(Interval(1,3));
    A.push_back(Interval(2,4));
    A.push_back(Interval(7,8));
    A.push_back(Interval(5,10));
    A.push_back(Interval(9,12));
    vector<Interval> ret=Merge(A);
    for(auto a:ret)
        cout << a.start << "\t" << a.end << endl;
    Interval target(2,5);
    cout << Search(ret,target) << endl;
    return 0;
}
