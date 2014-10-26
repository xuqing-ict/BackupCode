/**
 * @file countingObj.cc
 * @brief counting obj in a class , persudo ctor + static counting
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-30
 */

#include <bits/stdc++.h>
using namespace std;

class A
{
    class tooManyObject{};//exception class
private:
    static const size_t maxObjects=3;
    A();
    A(const A &); //If the maxObjects==1 ,the copy ctor need not be implemented
public:
    static size_t numObjects;
    static A *makeA()
    {
        return new A();
    }
    static A *makeA(const A &rhs)
    {
        return new A(rhs);
    }
   ~A(){--numObjects;}
};
size_t A::numObjects=0;
A::A()
{
  if(numObjects >= maxObjects)
  {
    throw tooManyObject();
    cout << "xq" << endl;
  }
  numObjects++;
  cout << "A ctor..." << endl;
}
A::A(const A &rhs)
{
  if(numObjects >= maxObjects)
  {
    throw tooManyObject();
    cout << "xq" << endl;
  }
  numObjects++;
  cout << "A copy ctor..." << endl;
}
int main()
{
    A *p1=A::makeA();
    cout << A::numObjects << endl;
    A *p2=A::makeA(*p1);
    cout << A::numObjects << endl;
    A *p3=A::makeA();
    cout << A::numObjects << endl;
    A *p4=A::makeA(*p3);
    cout << A::numObjects << endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}
