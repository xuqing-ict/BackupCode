/**
 * @file mismatch.cc
 * @brief mismatch
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-16
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1 = "12345", s2 = "12348";
  auto p = mismatch(s1.begin(), s1.end(), s2.begin());
  cout << *p.first << "\t" << *p.second << endl;
  return 0;
}
