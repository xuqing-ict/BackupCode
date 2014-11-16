//��ֹexception����������������Ҫ������ԭ��
// 1 ��ֹ���쳣��������е�ջչ����Ϊʱ��������terminate���������򽫻��������ʱ����ʵ����û����ô���ء�
// 2 ����Э��ȷ��destructor�����Ӧ����ɵ����еĶ�����

#include <bits/stdc++.h>
using namespace std;
/*
class myexception{};

class Session
{
public:
    Session()
    {
        logCreation();
    }

    ~Session()
    {
        try{ //�����try catch���Ǻ���Ҫ��
            logDestruction();
        }catch(...){
            cout << "catch exception..." << endl;
        }
    }

private:
    static void logCreation(){cout << "enter..." << endl;}
    static void logDestruction() {cout << "out..." << endl;throw myexception();}
};

int main()
{
    Session s;
    return 0;
}
*/

class Base{
public:
    Base(){}
    Base(const Base &){cout << "copy ctor in Base..." << endl;}
};

class Derived : public Base {
public:
    Derived(){}
    Derived(const Derived &b):Base(b){cout << "copy ctor in Derived..." << endl;}
};

void f()
{
    Derived d;
    Base & b = d;
    throw b;
}

void test()
{
    try{
        f();
    }catch(Base)
    {
        cout << "catch..." << endl;
    }
}
