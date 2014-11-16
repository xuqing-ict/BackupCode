#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual Base &operator=(const Base &rhs)
    {
        cout << "operator= in Base..." << endl;
    }
    virtual ~Base(){}
};
class Derived:public Base
{
public:
    Derived &operator=(const Base &rhs)
    {
        cout << "operator= in Derived..." << endl;
    }
    /*Derived &operator=(const Derived &rhs)
    {
        cout << "operator= in Derived non virtual..." << endl;
    }*/
    ~Derived(){}
};
int main()
{
    Derived d1,d2;
    d1 = d2;
    Base *p1 = &d1;
    Base *p2 = &d2;
    *p1 = *p2;
    return 0;
}
