#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void f(int i=0) {cout << "f() in Base..." << i << endl;}
};
class Derived:public Base
{
public:
    void f(int i=1){cout << "f() in derived..." << i << endl;}
};

int main(void)
{
    Base *b = new Derived();
    b->f();
    unordered_map<string,vector<string> > a;
    string s="123";
    a[s] = vector<string>(3,"");
    cout << a[s].size() << endl;
    return 0;
}
