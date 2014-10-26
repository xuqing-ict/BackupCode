/**
 * @file find.cc
 * @brief find template
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-04
 */
#include <bits/stdc++.h>
using namespace std;
namespace xuqing
{
template< class iterator, class T>
iterator find(iterator first, iterator end, const T &value)
{
  while(first != end && *first != value)
          ++first;
  return first;
}
}

int main()
{
    vector<int>vec = {1,2,3,4,5};
    auto ret = xuqing::find(vec.begin(), vec.end(), 9);
    if(ret == vec.end()) cout << "Not found!!!" << endl;
    else cout << *ret << endl;
    return 0;
}
