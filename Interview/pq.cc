/**
 * @file pq.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-17
 */

//priority_queue
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

struct mycompare : public binary_function<const P, const P, bool>
{
    bool operator()(const P &lhs, const P &rhs)
    {
        return lhs.second > rhs.second;
    }
};


int main(void)
{
    priority_queue<P,vector<P>,mycompare> pq;
    pq.push(make_pair(2,3));
    for(int i=0;i<5;++i)
        pq.push(make_pair(i,i+2));
    cout <<pq.top().first<< "\t" << pq.top().second << endl;
    vector<vector<int> > A;
    for(int i=0;i<3;++i)
        A.push_back(vector<int>(i,0));
    for(int i=0;i<A.size();++i)
        cout << A[i].size() << endl;
    return 0;
}
