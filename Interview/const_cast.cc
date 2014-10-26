/**
 * @file const_cast.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-01
 */

//const_cast的应用
#include <bits/stdc++.h>
using namespace std;

void change(int *a)
{
    *a = 3;
    cout << *a << endl; //3
}
int main(void)
{
    const int a = 4;
    cout << a << endl; //4
    change(const_cast<int *>(&a));
    cout << a << endl; //4
    return 0;
}
