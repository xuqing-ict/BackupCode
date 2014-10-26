/**
 * @file delNULL.cc
 * @brief delete null ptr is safety
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-01
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *p = NULL;
    delete p;
    return 0;
}
