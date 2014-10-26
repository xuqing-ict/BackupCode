/**
 * @file iterator.cc
 * @brief iterator
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-15
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a,b;
    for(int i=1; i<=5; ++i)
    {
        a.push_back(i);
        b.push_back(i*10);
    }
    vector<int> c;
    c.reserve(a.size() + c.size());
    copy(a.begin(), a.end(),back_inserter(c));
    ostream_iterator<int> out(cout , "\t");
    copy(a.begin(), a.end(), out);
    cout << endl;
    copy(c.begin(), c.end(),out);
    cout << endl;
    cout << a.size() << "\t" << c.size() << endl;
    cout << a.capacity() << "\t" << c.capacity() << endl;

    list<int> l1;
    for(int i=1;i<=5;++i)
        l1.push_back(i);
    copy(l1.begin(), l1.end(),out);
    cout << endl;
    list<int> l2;
    copy(l1.begin(), l1.end(), front_inserter(l2));
    copy(l2.begin(), l2.end(),out);
    cout << endl;
    return 0;
}
