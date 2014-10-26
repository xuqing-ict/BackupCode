/**
 * @file sharedPtrCycleRef.cc
 * @brief shared ptr cycle reference
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */

#include <bits/stdc++.h>
using namespace std;
class B;

class A
{
public:
  A() {cout << "A::A" << endl;}
  ~A() {cout << "A::~A" << endl;}
  shared_ptr<B> b;
};

class B
{
public:
  B() {cout << "B::B" << endl;}
  ~B() {cout << "B::~B" << endl;}
  //shared_ptr<A> a;
  weak_ptr<A> a; //break the cycle reference
};
int main()
{
  shared_ptr<A> x(new A);
  x->b = shared_ptr<B>(new B);
  x->b->a = x;  //cycle refrence counting
  //change any pointer in this cycle into weak_ptr would break the cycle
  return 0;
}
