/**
 * @file static.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-27
 */
//static 局部变量
#include <bits/stdc++.h>
using namespace std;

void func()
{
    cout << "func called..." << endl;
    return;
}

void Test()
{
    cout << "Test called..." << endl;
    static int  i = (func(),1);
}

int main(void)
{
    for(int i=0;i<3;++i)
        Test();   
    return 0;
}
