/**
 * @file tmp.cc
 * @brief TMP
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-27
 */

#include <bits/stdc++.h>
using namespace std;

template<unsigned int n>
struct factorial
{
  //enum {value=n+factorial<n-1>::value};
  static const unsigned long value = n + factorial<n-1>::value;
};

template<>
struct factorial<0>
{
  //enum{value=1};
  static const unsigned long value = 1;
};

int main()
{
  cout << factorial<100>::value << endl;
  return 0;
}
