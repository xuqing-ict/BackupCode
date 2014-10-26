/**
 * @file ObjectsOnHeap.cc
 * @brief build object in heap only
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-06
 */

#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A(){}
    A(const A &){}
    void destory(){delete this;}
//private:
protected:
    ~A(){}
};

class B:public A
{
public:
    B(){}
};
int main()
{
//  A a; //无法通过，因为析够函数是private的. 
    A *p = new A;
    //delete p; //无法通过，因为此处的delete是为默认调用A的析构函数,于是就必须自己定义函数来delete对象本身！！！见destory函数
    p->destory();
     B b; //无法通过，因为在构造B的过程中必须调用A的默认构造函数，然而该函数却是private的 将A的构造函数声明为protected便可以解决这个问题
  return 0;
}


