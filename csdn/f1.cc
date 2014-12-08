/**
 * @file f1.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-12-07
 */


#include <iostream>
using namespace std;

int f(int x, int y)
{
    return x+y;
}

int main(void)
{
    int (*fptr)(int,int) ;
    fptr = f;
    cout << (*fptr)(2,3) << endl;
    return 0;
}
