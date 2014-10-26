/**
 * @file multiInheritance.cc
 * @brief multi inheritance
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-25
 */
#include <bits/stdc++.h>
using namespace std;

class Base1
{
public:
  virtual ~Base1(){}
private:
  void func(int ){cout << "func in Base1..." << endl;}
};

class Base2
{
public:
  virtual ~Base2(){}
  void func(){cout << "func in Base2..." << endl;}
};

class Derived:public Base1, public Base2
{
};
int main()
{
  Derived d;
  d.func(0);
  return 0;
}
