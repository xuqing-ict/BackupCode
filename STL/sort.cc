/**
 * @file sort.cc
 * @brief sorts!!!
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-15
 */

#include <bits/stdc++.h>
using namespace std;

ostream_iterator<int> out(cout , "\t");
int main()
{
    vector<int> A = {1,0,9,3,4,29,89,7,45};
    //find Top 5
    partial_sort(A.begin(), A.begin() + 5, A.end(),greater<int>());
    copy(A.begin(),A.end(), out);
    cout << endl;
    nth_element(A.begin(), A.end()+4,A.end(),less<int>());
    copy(A.begin(),A.end(), out);
    cout << endl;
    auto mid = A.begin() + (A.end()-A.begin())/2;
    nth_element(A.begin(), mid, A.end());
    copy(A.begin(),A.end(), out);
    cout << endl;
    cout << *mid << endl;
    vector<int> B = {1,2,3,4,10,3,4};
    vector<int>::size_type pos = B.size() * 0.50;
    nth_element(B.begin(), B.begin()+pos, B.end());
    copy(B.begin(),B.end(), out);
    cout << endl;
    cout << *(B.begin() + pos) << endl;
    cout << B.size() << endl;
    B.erase(remove(B.begin(),B.end(),3),B.end());
    cout << B.size() << endl;
    B.erase(remove(B.begin(),B.end(),3),B.end());
    copy(B.begin(),B.end(), out);
    cout << endl;

    return 0;
}
