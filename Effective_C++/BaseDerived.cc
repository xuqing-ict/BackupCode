/**
 * @file BaseDerived.cc
 * @brief NVI non-virtual interface
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-23
 */

#include <bits/stdc++.h>
using namespace std;

class Base
{
protected:
  //func如果是private，在derived函数中可以重新定义。
  //但是由于它是private，不能再Derived类中直接调用，必须是protected，才能在Derived中使用Base::func()
  virtual void func(){cout << "func in Base..." << endl;}
public:
  void Func(){cout << "Func in Base..." << endl; func();}
};

class Derived:public Base 
{
private:
  virtual void func(){cout << "func in Derived..." << endl;}
public:
  void Func2(){cout << "Func in Derived..." << endl;Base::func(); /*func();*/}
};
int main()
{
  Derived d;
  d.Func2();
  return 0;
}
