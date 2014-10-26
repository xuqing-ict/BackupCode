/**
 * @file for_each.cc
 * @brief for_each
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-04
 */
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct plus2
{
  void operator() (T &x ) const
  {
      x += 2;
  }
};
int main()
{
    vector<int> vec = {1,2,3,4,5};
    for_each(vec.begin(), vec.end(), plus2<int> ());
    copy(vec.begin(),vec.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    return 0;
}
