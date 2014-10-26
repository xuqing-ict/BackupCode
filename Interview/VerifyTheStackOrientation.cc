/**
 * @file VerifyTheStackOrientation.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-25
 */
//确定栈的增长方向
#include <bits/stdc++.h>
using namespace std;

//只定义一个函数是不够的，于是需要嵌套的调用一个函数即可
void g()
{
    int val;
    cout << "val in g : " << &val << endl;
    return;
}

void f()
{
    g();
    int val;
    cout << "val in f : " << &val << endl;
    return;
}

int main(void)
{
    f();  
    return 0;
}
