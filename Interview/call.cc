/**
 * @file call.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-12
 */

#include <bits/stdc++.h>
using namespace std;
/*
class Base
{
public:
    virtual int func(int x) { cout << "Base virtual int" << endl; }
    double func(double x) { cout << "Base double" << endl; }
    short func(short x) { cout << "Base short" << endl; }
};

class Derived : public Base
{
public:
    short func(short) { cout << "Derived short" << endl; }
    double func(double) { cout << "Derived double" << endl; }
};
*/
class Base
{
public:
    virtual int func(int x) { cout << "Base virtual int" << endl; }
    int func(short x) { cout << "Base double" << endl; }
    int func(float x) { cout << "Base short" << endl; }
};

class Derived : public Base
{
public:
    int func(short) { cout << "Derived short" << endl; }
    int func(double) { cout << "Derived double" << endl; }
};




int main(void)
{
    Derived d;
    Base *p1 = &d;
    p1->func(77777);
    p1->func(77777.7f);
    p1->func(1234);


    Derived *p2 = &d;
    p2->func(77777);
    p2->func(777.7f);
    p2->func(123);

    return 0;
}
