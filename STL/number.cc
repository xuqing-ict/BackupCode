/**
 * @file number.cc
 * @brief count  find  ....
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-19
 */

#include <bits/stdc++.h>
using namespace std;

ostream_iterator<int> out(cout, "\t");

int main()
{
    vector<int> A = {1,1,2,3,4,5,5,5,5,6,34,155};
    cout << count(A.begin(), A.end(), 8) << endl;
    cout << distance(A.begin(), find(A.begin(), A.end(), 155)) << endl;
    cout << "There are " << distance(lower_bound(A.begin(), A.end(), 5), upper_bound(A.begin(),A.end(),5)) << " 5 "<< endl;
    auto it = equal_range(A.begin(), A.end(), 5);
    cout << distance(it.first, it.second) << endl;
    copy(A.begin(), A.end(), out);
    cout << endl;
    A.erase(A.begin(), lower_bound(A.begin(), A.end(), 5));
    copy(A.begin(), A.end(), out);
    cout << endl;
    A.erase(upper_bound(A.begin(), A.end(), 5), A.end());
    copy(A.begin(), A.end(), out);
    cout << endl;
    list<int>::iterator first, last;
    sort(first, last);
    return 0;
}
