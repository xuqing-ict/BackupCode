/**
 * @file priority_queue.cc
 * @brief priority_queue
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-13
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int a[] = {1,4,5,2,3,7,9,8,6};
  priority_queue<int,vector<int>,greater<int> > q(a,a+sizeof(a)/sizeof(int));
  for(int i=0; i<q.size();++i)
      cout << q.top() << "\t";
  cout << endl;
  while(!q.empty())
  {
      cout << q.top() << "\t";
      q.pop();
  }
  cout << endl;
  return 0;
}
