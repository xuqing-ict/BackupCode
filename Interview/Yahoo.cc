/**
 * @file Yahoo.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-22
 */
//程序改错题
#include <bits/stdc++.h>
using namespace std;

struct A
{
    A(int){}
    A(){}
    void func(){}
};

int main(void)
{
    A a(2);
    a.func();
    //A b(); //C++会把此处当作是一个函数声明，也就是说在调用默认构造函数的时候后面不能使用括号。
    A b;
    b.func();
    return 0;
}
