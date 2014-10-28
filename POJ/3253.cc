/**
 * @file 3253.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-27
 */

//Fence repair
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
#define For(i,n) for(int i=0;i<(n);++i)

typedef long long ll;

int len[20001];
int n;

ll minCost()
{
  priority_queue<int,vector<int>,greater<int> > pq;
  For(i,n)
      pq.push(len[i]);
  ll ans=0;
  while(!pq.empty())
  {
    int l1 = pq.top(); pq.pop();
    if(pq.empty())return ans; //only one element 
    int l2 = pq.top();pq.pop();
    ans += (l1+l2);
    pq.push(l1+l2);
  }
  return ans;
}

int main(void)
{
    //cout << INT_MAX << endl;
  while(scanf("%d",&n) != EOF)
  {
    fill_n(len,20001,0);
    For(i,n)
        cin >> len[i];
    cout << minCost() << endl;
  }
  return 0;
}

