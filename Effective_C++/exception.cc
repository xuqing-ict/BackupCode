/**
 * @file exception.cc
 * @brief exception specification
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-02
 */

//1  不能用在typedef中
//2  只能将throw的少的赋值给throw的多的（less restrictive）,
//3  如果基类的需函数有throw的话，那么派生类中该函数的throw应该完全与基类的一致 
#include <bits/stdc++.h>
using namespace std;

class Base
{
  public:
      virtual void f() throw(bad_alloc)
      {
          cout << "f in Base..." << endl;
      }
      virtual ~Base(){}
};

class Derived:public Base
{
  public:
      virtual void f() throw(bad_alloc)
      {
          cout << "f in Derived..." << endl;
      }
};

void func() throw(bad_alloc)
{
    int x = 5/0;
    cout << "func throw bad_alloc..." << endl;
}

//void (*fp)() throw (bad_alloc, runtime_error);
//void (*fp)() throw ( runtime_error);
void (*fp)() ;
//typedef void (*fp)() throw ( runtime_error);  //不能使用typedef

void err_func()
{
    cout << "DIVIDE BY ZERO!!!" << endl;
}
int main()
{
  set_unexpected(err_func);
  Derived d;
  d.f();
  fp = func;
  (*fp)();
  return 0;
}
