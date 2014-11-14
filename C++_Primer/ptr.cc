/**
 * @file ptr.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-05
 */

#include <iostream>
using namespace std;

class A
{
public:
    void print() {cout << "A :"  << a << endl;}
private:
    int a;

};
int main(void)
{
    A *p = NULL;
    p->print();
    (*p).print();
    ((A*)(NULL))->print();
    return 0;
}
