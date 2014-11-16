#include <bits/stdc++.h>
using namespace std;

struct strCmp:public binary_function<string *, string *, bool>
{
    bool operator() (const string *lhs, const string *rhs) const
    {
        return *lhs < *rhs;
    }
};

struct strCmp2
{
    template<class T>
    bool operator()( T lhs, T rhs) const
    {
        return *lhs < *rhs;
    }
};
int main()
{
    set<string * , strCmp2> s;
    string a[] = {"b","a","e","d"};
    s.insert(&a[3]);
    s.insert(&a[2]);
    s.insert(&a[1]);
    s.insert(&a[0]);
    for(set<string *>::const_iterator it = s.begin(); it != s.end();++it)
    {
        cout << **it << endl;
    }
    return 0;
}
