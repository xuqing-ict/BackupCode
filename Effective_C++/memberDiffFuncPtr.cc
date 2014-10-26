/**
 * @file memberFuncPointer.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-06
 */
//member function pointer
#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual ~Base(){}
    virtual void vFunc(int x, char *p)
    {
        cout << "vFunc in Base..." << endl;
    }
    virtual void vFunc2(int x, char *p)
    {
        cout << "vFunc2 in Base..." << endl;
    }
    static void static_func(){cout << "static_func in Base..." << endl;}

    void memfunc() {cout << "memfunc in Base..." << endl;}
    void memfunc2() {cout << "memfunc2 in Base..." << endl;}
    int ns_data;
    static int static_data;
};

int Base::static_data = 0;
class Derived:public Base{
public:
    virtual void func(int x, char *p)
    {
        cout << "func in Derived..." << endl;
    }
};

int main(void)
{
    //取非static成员变量的地址，取得是偏移量。
    cout << "non static data member address = " << &Base::ns_data << endl; 
    //取static成员变量的地址，取得是实际的地址
    cout << "static data member address = " << &Base::static_data << endl;

    //取非static，非虚函数的地址，取的是函数在内存中的地址
    cout << "non static member function ptr = " << (void *)(&Base::memfunc) << endl;
    cout << "non static member function ptr2 =  " << (void *)&Base::memfunc2 << endl;
    
    cout << "static memeber function address = " << (void *)&Base::static_func << endl;


    //cout << "virtual dtor function address = " << (&Base::~Base) << endl;
    cout << "virtual memeber function address = " << (&Base::vFunc) << endl;
    cout << "virtual memeber function address = " << (&Base::vFunc2) << endl;
    return 0;
}
