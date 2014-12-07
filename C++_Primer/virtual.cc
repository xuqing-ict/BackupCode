/**
 * @file virtual.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-12-04
 */

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void func() = 0;
};
void Base::func()
{
    cout << "Hello..." << endl;
}

class Derived : public Base
{
public:
    void func() {
        Base::func();
    }
};

int main(void)
{
    Derived d;
    d.func();
    return 0;
}
