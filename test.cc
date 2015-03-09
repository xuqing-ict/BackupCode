/**
 * @file test.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2015-01-20
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    unordered_map<int,vector<int> > m;
    m[1] = {1,2,3};
    m[9] = {4,5,6};
    m[87] = {7,8,9};
    for(auto item : m)
    {
        cout << item.first << "\t" ;
        for(auto a : item.second)
            cout << a << "\t";
        cout << endl;
    }
    for(map<int, vector<int> >::iterator it = m.begin(); it != m.end(); ++it)
    {

        for(map<int, vector<int> >::iterator jt = it; jt != m.end(); ++jt)
            cout << (*it).first << "\t" << (*jt).first << endl;
    }
    /*
    vector<int> A = {1,2,3,4,5,6,7};
    vector<int> B(A.begin(), A.end());
    for(auto a : A) cout << a << "\t"; cout << endl;
    for(auto a : B) cout << a << "\t"; cout << endl;
    B.assign(A.begin()+5,A.end());
    for(auto a : B) cout << a << "\t"; cout << endl;
    */
    /*
    set<int> a = {1,2,2,3};
    for(auto i : a) cout << i << "\t";
    cout << endl;
    set<int> & b = a;
    for(auto i : b) cout << i << "\t";
    cout << endl;
    b.insert(100);
    for(auto i : a) cout << i << "\t";
    cout << endl;
    for(auto i : b) cout << i << "\t";
    cout << endl;
    assert(&a == &b);
    */ 
    return 0;
}
