// Last Update:2014-07-16 17:53:43
/**
 * @file allocator.c
 * @brief allocator functions
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-16
 */

#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A(){cout << "A ctor..." << endl;}
    ~A() {cout << "A dtor..." << endl;}
    A(const A & rhs){cout << "A copy ctor..." << endl;}

};
int main()
{
    vector<A> Vec;
    Vec.resize(3);
    uninitialized_fill(Vec.begin(), Vec.end(), A());
    return 0;
}
