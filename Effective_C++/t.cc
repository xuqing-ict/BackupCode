/**
 * @file t.cc
 * @brief test
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-01
 */

#include <iostream>
#include <string>
using namespace std;

class A
{
private:
    int x,y;
public:
    A(int _x=0,int _y=0):x(_x),y(_y){}
};

int main(void)
{
    A vec[10];
    string s1 = "Hello";
    char *p = &s1[1];
    string s2 = s1;
    cout << s1 << "\t" << s2 << endl;
    *p = 'a';
    cout << s1 << "\t" << s2 << endl;
    return 0;
}
