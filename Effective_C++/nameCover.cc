/**
 * @file nameCover.cc
 * @brief name cover in inherient
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-22
 */
#include <bits/stdc++.h>
using namespace std;
class Base
{
public:
  void func1(int x){cout << "func1(int) in Base ..." << endl;}
  void func2(){cout << "func2() in Base ..." << endl;}
};

class Derived : public Base
{
public:
  using Base::func1;
  void func1() {cout << "func1() in Derived..." << endl;}
  //func1(int) in Derived cover the func1(int) in Base
  void func1(int x) {cout << "func1(int) in Derived..." << endl;}
};
int main()
{
  Derived d;
  d.func1(3);
  d.func2();
  return 0;
}
