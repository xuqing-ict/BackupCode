/**
 * @file test.cc
 * @brief constraints the count of objects of a class
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-23
 */

#include <bits/stdc++.h>
using namespace std;

class A
{
    //friend void f();
private:
    static A a;
    A() {cout << "A constructed..." << endl; }
};
/*
void f()
{
    static A  a;
    return;
}
*/
A A::a;



int main()
{
  
    /*
  f();
  f();
  f();
  */
  return 0;
}
