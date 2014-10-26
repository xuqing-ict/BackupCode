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

class SomeClass
{
public:
    virtual void some_member_func(int x, char *p)
    {
        cout << "In SomeClass..." << endl;
    }
};
class DerivedClass:public SomeClass
{
public:
    virtual void some_member_func(int x, char *p)
    {
        cout << "In DerivedClass..." << endl;
    }

};

int main(void)
{
    typedef void (SomeClass::*SomeClassMFP)(int ,char*);
    SomeClassMFP my_memfunc_ptr;
    my_memfunc_ptr = &SomeClass::some_member_func;
    SomeClass *s = new DerivedClass();
    (s->*my_memfunc_ptr)(0,nullptr);
    delete s;
    return 0;
}
