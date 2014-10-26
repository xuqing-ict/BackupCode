/**
 * @file sortString.cc
 * @brief sort string
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-04
 */

#include <bits/stdc++.h>
using namespace std;

//lhs < rhs
bool cmp(const string &lhs, const string &rhs)
{
  const int n1=lhs.size(),n2=rhs.size();
  for(int i=0;i<min(n1,n2);++i)
  {
    if(lhs[i] == rhs[i]) continue;
    else if(lhs[i] < rhs[i]) return true;
    else return false;
  }
  return (n1>n2);
}


int main(void)
{
  vector<string> vec = {"123","120","2345","234","234"};
  cout << *min_element(vec.begin(),vec.end(), cmp) << endl;
  cout << *max_element(vec.begin(), vec.end(), cmp) << endl;
  return 0;
}
