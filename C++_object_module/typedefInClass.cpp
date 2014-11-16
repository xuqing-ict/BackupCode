#include <iostream>
using namespace std;

typedef int LENGTH;
class Test
{
    typedef float LENGTH;
public:
    void set(LENGTH x){_val = x;}
    LENGTH get(){return _val;}
    static int getT()  {cout << &Test::t << endl;return t;}
private:
    //typedef float LENGTH;
    LENGTH _val;
    static int t;
};
int Test::t = 10;

Test func()
{
    Test a;
    cout << "Call func..." << endl;
    return a;
}


int main()
{
    Test obj1;
    cout << obj1.getT() << endl;
    cout << Test::getT() << endl;
    Test *p = &obj1;
    cout << p->getT() << endl;
    Test *p2;
    cout << p2->getT() << endl;
    //Test obj2 = func();
    cout << func().getT() << endl;

    return 0;
}
