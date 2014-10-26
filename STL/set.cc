/**
 * @file set.cc
 * @brief set
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-26
 */

#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

int main()
{
  set<int> s1;
  unordered_set<int> s2;
  vector<int> a = {5,3,2,4,1};
  for(int i=0;i<5;++i)
  {
    s1.insert(a[i]);
    s2.insert(a[i]);
  }
  cout << "set\t";
  for(auto a:s1)
    cout << a << "\t";
  cout << endl;
  cout << "uset\t";
  for(auto a:s2)
    cout << a << "\t";
  cout << endl;
  return 0;
}
