#include <iostream>
using namespace std;

/*
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
};

class Derived
{
private:
    Base2 b2;
    Base b;
    int x;
public:
    //Derived(int _x){  x = _x; }
    ~Derived(){}
};

*/
/*
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
    Derived(int _x):x(_x){}
    Derived(string _str):str(_str){}
    ~Derived(){}
};

*/
class Base
{
private:
    int x;
public:
    Base(){cout << "call Base default ctor..." << endl;}
    virtual void vCall(){cout << "virtual call in Base..." << endl;}
    virtual ~Base(){}
};
class Derived:public Base
{
private:
    int x ;
public:
    void vCall(){x=1;cout << "virtual call in Derived..." << endl;}

};
void vCall(Base &b)
{
    b.vCall();
}
/*
class Base
{
public:
    int x;
    int getX() const {return x;};
};
*/
int main()
{
    Derived d;
    vCall(d);
    return 0;
}
