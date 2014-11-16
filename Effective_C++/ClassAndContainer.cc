//定义类的对象数组
#include <bits/stdc++.h>
using namespace std;

/*class A
{
public:
    A() {cout << "A ctor called..." << endl;}
    A(const A&) {cout <<"A copy ctor called..." << endl;}
};

int main(void)
{
    vector<A> vec;
    for(int i=0;i<5;++i)
    {
        cout << " i = " << i << endl;
        vec.push_back(A());
    }
    vector<unique_ptr<A> > v;
    unique_ptr<A> q( new A() );
    v.push_back( q );

    return 0;
}
*/
int main(void)
{
    /*
    unique_ptr<int> foo;
    unique_ptr<int> bar;
    int *p = nullptr;

    foo = unique_ptr<int>(new int(10));
    cout << *foo << endl;
    bar = std::move(foo);
    assert(foo == nullptr);
    if(bar) cout << *bar << end;
        */
    char a[4] = "123";
    cout << (void *)a << endl;
    cout << "TEST : " << (void *)&(a[0]) << endl;
    //cout << &((char)(*a)) << endl;
    string s = "456";
    cout << (void *)&(s[0]) << endl;
    //cout << (void *)((s.c_str()) << endl;
    string s2=s;
    cout << (void *)(s.c_str()) << endl;
    cout << (void *)(s2.c_str()) << endl;
    s2[0] = '9';
    cout << (void *)(s2.c_str()) << endl;
    return 0;
}
