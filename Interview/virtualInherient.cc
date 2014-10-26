/**
 * @file virtualInherient.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-25
 */

/*
#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
    int x;
public:
    virtual void func1(){}
    virtual void func2(){}
};

class Derived : virtual public Base
{
private:
    virtual void func3(){}
    virtual void func4(){}
};

int main(void)
{
    cout << sizeof(void *) << endl;
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    return 0;
}
*/
#include <iostream>

using namespace std;


class base
{
private:
    int a;
public:
    void bfun()
    {
    }
    virtual void vfun1()
    {
    }
    virtual void vfun2()
    {
    }
};

class derived :public base
{
private:
    int b;
public:
    void dfun()
    {
    }
    virtual void vfun1()
    {
    }
    virtual void vfun3()
    {
    }
};

int main(void)
{
    cout<<"base's size is "<<sizeof(base)<<endl;
    cout<<"derived's size is "<<sizeof(derived)<<endl;
    return 0;
}
