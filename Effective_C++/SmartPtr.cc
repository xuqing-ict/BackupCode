/**
 * @file SmartPtr.cc
 * @brief when smart ptr meets inherentance
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-31
 */

//smart ptr and Inherentance
#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual ~Base() {}
    virtual void print() = 0;
};

class Son1 :public Base
{
public:
    ~Son1(){}
    void print()
    {
        cout << "print in Son1..." << endl;
    }
};

class Son2 :public Base
{
public:
    ~Son2(){}
    void print()
    {
        cout << "print in Son2..." << endl;
    }
};

class Third1 :public Son1
{
public:
    ~Third1(){}
    void print() {cout << "print in Third1..." << endl;}
};

template<class T>
class Auto_ptr
{
private:
    T *pointee;
public:
   Auto_ptr(T *ptr=0):pointee(ptr){}
   ~Auto_ptr(){delete pointee;}
   Auto_ptr<T> &operator=(Auto_ptr<T> &rhs)
   {
      if(this==&rhs) return *this;
      delete pointee;
      pointee = rhs.pointee;
      rhs.pointee = nullptr;
      return *this;
   }
   //copy ctor
  Auto_ptr(Auto_ptr<T> &rhs)
  {
    pointee = rhs.pointee;
    rhs.pointee = nullptr;
  }
  //operator *
  Auto_ptr<T> &operator*()
  {
      return *pointee;
  }
  //operator->
  T *operator->()
  {
      return pointee;
  }
  //non-virtual template function
  template<class C>
  operator Auto_ptr<C> ()
  {
      return Auto_ptr<C>(pointee);
  }
};

void f(Base *rhs)
{
    cout << "f called..." << endl;
    return;
}

int main(void)
{
    Auto_ptr<Son1> p1(new Son1());
    f(p1); //SmartPtr.cc:95:9: error: cannot convert ‘Auto_ptr<Son1>’ to ‘Base*’ for argument ‘1’ to f(Base*),WHY!!!!
    return 0;
}
