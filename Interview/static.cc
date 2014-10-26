/**
 * @file static.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-15
 */
#include <bits/stdc++.h>
using namespace std;

static int n;
void f();
int main()
{
    n = 20;
    cout << n << endl;
    f();
    return 0;
}
void f()
{
    n++;
    cout << n << endl;
}
