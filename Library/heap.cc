/**
 * @file heap.cc
 * @brief heap
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-24
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> data = {1,2,3,4,5,6,7,8};
  make_heap(data.begin(), data.end());
  for(auto a: data)
    cout << a << " ";
  cout << endl;
  sort_heap(data.begin(), data.end());
  for(auto a: data)
    cout << a << " ";
  cout << endl;
  return 0;
}
