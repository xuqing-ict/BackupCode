// Last Update:2014-07-13 10:38:26
/**
 * @file container.cpp
 * @brief container
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-10
 */
#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A() {cout << "A ctor called..." << endl;}
    ~A() {cout << "A dtor!!!" << endl;}
};
ostream_iterator<int> out(cout, "\t");
int main()
{
  vector<A> vec;
  vec.reserve(2);
  cout << " 0 == " << vec.size() << endl;
  vec.resize(4);
  cout << "4 ctor 4 == " << vec.size() << endl;
  vec.reserve(3);
  cout << "0 dtor 4 == " << vec.size() << endl;
  return 0;
}

