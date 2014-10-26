/**
 * @file exception_2.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-08
 */

#include <bits/stdc++.h>
using namespace std;

class myexception{};
class anotherexception{};
void func() throw(myexception)
{   
    anotherexception p;
    throw p;
    cout << "never be here..." << endl;
}

int main(void)
{
    func();

    return 0;
}
