#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "call Base default constructor..." << endl;
    }
    virtual ~Base(){}
};

class Base2
{
public:
    Base2(){cout << "call Base2 default constructor..." << endl;}
    virtual ~Base2(){}
};

class Member
{
public:
    Member(){cout << "call Member default constructor..." << endl;}
};

class Derived : public Base, public Base2
{
private:
    int x;
    Member m;
    string str;
public:
    Derived(int _x):x(_x){cout<< "Derived(int) called...." << endl;}
    Derived(string _str):str(_str){}
    ~Derived(){}
};
int main()
{
    Derived d(0);
    return 0;
}
