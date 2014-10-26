/**
 * @file NeverWriteTheDefaultParameter.cc
 * @brief never write the default parameter
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-24
 */

//绝对不要重新定义继承而来的缺省的参数值
//因为参数是静态绑定的，参数是动态绑定的。
#include <bits/stdc++.h>
using namespace std;
class Base
{
public:
  virtual ~Base(){}
  virtual void print(int x = 1 )  {cout << "In base : " << x << endl;}
};
class Derived:public Base
{
public:
  void print(int x = 2) {cout << "In Derived : " << x << endl;}
};

int main()
{
  Derived d;
  d.print();
  Base *b = new Derived();
  b->print(); //x = 1, 
  delete b;
  return 0;
}
