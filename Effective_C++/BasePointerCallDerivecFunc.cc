/**
 * @file BasePointerCallDerivecFunc.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-04
 */
//基类的指针不可以调用派生类自身定义的函数（不是虚函数）
#include <bits/stdc++.h>
using namespace std;


class Base
{
public:
    void FuncInBase(){cout << "Func in Base..." << endl;}
};
class Derived:public Base
{
public:
    void FuncInDerived() {cout << "Func in Derived..." << endl;}
};


int main(void)
{
    Base *p = new Derived();
    p->FuncInBase();
    p->FuncInDerived();
    return 0;
}
