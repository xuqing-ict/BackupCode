// Last Update:2014-08-23 15:56:59
/**
 * @file EndianTest.c
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-23
 */

#include <bits/stdc++.h>
using namespace std;

union Elem
{
    int x;
    char y;
};

int main()
{
    Elem  e ;
    e.x = 65;
    cout << e.y << endl;
    return 0;
}
