//阻止exception逃离析构函数，主要是两个原因：
// 1 防止在异常处理过程中的栈展开行为时，将调用terminate函数。程序将会结束，有时候其实错误并没有那么严重。
// 2 可以协助确保destructor完成它应该完成的所有的动作。

#include <bits/stdc++.h>
using namespace std;
/*
class myexception{};

class Session
{
public:
    Session()
    {
        logCreation();
    }

    ~Session()
    {
        try{ //这里的try catch块是很重要的
            logDestruction();
        }catch(...){
            cout << "catch exception..." << endl;
        }
    }

private:
    static void logCreation(){cout << "enter..." << endl;}
    static void logDestruction() {cout << "out..." << endl;throw myexception();}
};

int main()
{
    Session s;
    return 0;
}
*/

class Base{
public:
    Base(){}
    Base(const Base &){cout << "copy ctor in Base..." << endl;}
};

class Derived : public Base {
public:
    Derived(){}
    Derived(const Derived &b):Base(b){cout << "copy ctor in Derived..." << endl;}
};

void f()
{
    Derived d;
    Base & b = d;
    throw b;
}

void test()
{
    try{
        f();
    }catch(Base)
    {
        cout << "catch..." << endl;
    }
}
