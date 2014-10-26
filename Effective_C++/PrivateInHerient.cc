/**
 * @file PrivateInHerient.cc
 * @brief private inherience
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-25
 */

#include <bits/stdc++.h>
using namespace std;

class Base
{};
class Derived
{
  int x;
  Base b;
};
class Derived2:private Base
{
  int x;
};

int main()
{
  cout << sizeof(Derived) << endl;
  cout << sizeof(Derived2) << endl;
  return 0;
}
