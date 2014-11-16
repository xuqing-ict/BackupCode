//�ڶ��ؼ̳е�����£���ĳ�Ա�����ĵ���ʱ��������ִ�еĶ���
#include <iostream>

using namespace std;

class Base1
{
public:
    Base1(){cout << "Base1 ctor..." << endl;}
    virtual ~Base1(){cout << "Base1 dtor..." << endl;}
    virtual Base1 *clone() const{cout << "Base1 Clone..." << endl;}
};

class Base2
{
public:
    Base2(){cout << "Base2 ctor..." << endl;}
    virtual ~Base2(){cout << "Base2 dtor..." << endl;}
    virtual Base2 *clone() const{cout << "Base2 Clone..." << endl;}
};

class Derived:public Base1 , public Base2
{
public:
    Derived(){cout << "Derived ctor..." << endl;}
    virtual ~Derived(){cout << "Derived dtor..." << endl;}
    Derived *clone() const{cout << "Derived Clone..." << endl;}
};

int main()
{
    /*Derived d;
    d.clone();
    Base1 *p = new Derived;
    p->clone();
    delete p;
    */
    Base2 *p2 = new Derived;
    p2->clone();
    delete p2;
    return 0;
}
