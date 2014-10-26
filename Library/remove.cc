/**
 * @file remove.cc
 * @brief std::remove
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-26
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> A{1,2,3,4,5,6,7};
  auto end = remove(A.begin(), A.end(), 3);
  for(auto a = A.begin(); a!= end;++a)
  {
    cout << *a << " ";
  }
  cout << endl;
  return 0;
}
