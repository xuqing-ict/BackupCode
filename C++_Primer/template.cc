/**
 * @file template.cc
 * @brief template
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-13
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline int cmp(const T&lhs, const T&rhs)
{
    if (lhs<rhs) return -1;
    else if (lhs==rhs) return 0;
    else return 1;
}
int main(void)
{
  cout << cmp(1,2) << endl;
  return 0;
}
