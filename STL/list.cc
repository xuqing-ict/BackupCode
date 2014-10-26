/**
 * @file list.cc
 * @brief list 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-10
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int A[] = {1,1,2,3,2,2,4};
  list<int> l(A,A+sizeof(A)/sizeof(int));
  for(auto a:l)
      cout << a << "\t";
  cout << endl;
//  l.unique();
  //l.remove(2);
  //l.push_front(0);
  l.transfer(l.begin(),l.begin()+2,l.end());
  for(auto a:l)
      cout << a << "\t";
  cout << endl;

  /*
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  auto it=find(l.begin(), l.end(),2);
  cout << *it << endl;
  //it=l.erase(it);
  //cout << *it << endl;
  it=l.insert(it,100);
  cout << *it << endl;
  */
  
  return 0;
}
