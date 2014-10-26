/**
 * @file MapKey.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-12
 */
//a+bi as the key of 

#include <bits/stdc++.h>
using namespace std;


class Complex
{
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.a << "\t" << c.b;
        return os;
    }

private:
    int a;
    int b;
public:
    Complex(int _a = 0, int _b = 0):a(_a), b(_b){}
    const int len() const {return a*a + b*b;}
    bool operator<(const Complex &rhs) const
    {
        return len() < rhs.len();  
    }
};
int main(void)
{
    map<Complex,int> p;
    p[Complex(1,2)] = 5;
    p[Complex(1,2)] = 1;
    p[Complex(2,3)] = 5;
    p[Complex(3,3)] = 1;
    for(auto a:p)
        cout << a.first << "\t" << a.second << endl;
    return 0;
}
