/**
 * @file equal.cc
 * @brief some algorithm in STL
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-25
 */

#include <bits/stdc++.h>
using namespace std;

ostream_iterator<int> out(cout,"\t");

template<class T>
struct Cmp:public binary_function<T,T,bool>
{
    bool operator()(const T &x, const T &y)
    {
      return x<y;
    }
};

int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,3,4};
    cout << equal(v1.begin(),v1.end(),v2.begin()) << endl;
    iter_swap(v1.begin(),v1.begin()+2);
    copy(v1.begin(), v1.end(), out);
    cout << endl;
    make_heap(v2.begin(),v2.end(),less<int>());
    copy(v2.begin(),v2.end(), out);
    cout << endl;
    sort(v2.begin(), v2.end(),Cmp<int>());
    copy(v2.begin(),v2.end(), out);
    cout << endl;
    cout << logical_and<int>()(0,1) << endl;
    return 0;
}

