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
  vec.resize(4); //4 ctors
  //vec.reserve(3);//nothing
  cout << "-----------------------------------------------------------------------------" << endl;
  vec.resize(6); //(6-4) ctors 
  cout << vec.size() << endl;
  cout << "end main..." << endl;
 /* 
  vector<int> iVec = {1,5};
  vector<int> iVec2 = {7,8,9,10,11};
  //iVec.assign(iVec2.begin(),iVec2.begin()+3);
  iVec.insert(iVec.end(), iVec2.begin()+ 3, iVec2.end());
  cout << "iVec : "  << iVec.size() << "\t" << iVec.capacity() << endl;
  copy(iVec.begin(),iVec.end(), out);
  cout << endl;
  cout << "iVec2 : " << iVec2.size() << "\t" << iVec2.capacity() << endl;
  copy(iVec2.begin(),iVec2.end(), out);
  cout << endl;
  */
  
/*
  vector<int> iVec2 = {7,8,9,10,11};
  cout << "iVec2 : " << iVec2.size() << "\t" << iVec2.capacity() << endl;
  auto it = remove(iVec2.begin(), iVec2.end(),10);
  cout << *it << endl;
  iVec2.erase(it,iVec2.end());
  //iVec2.erase(remove(iVec2.begin(), iVec2.end(),10), iVec2.end());
  cout << "iVec2 : " << iVec2.size() << "\t" << iVec2.capacity() << endl;
  cout << iVec2.size() << endl;
  copy(iVec2.begin(),iVec2.end(), out);
  cout << endl;
  list<int> L = {1,2,3,4,5};
  cout << "L.size() " << L.size() << endl;
  L.remove(3);
  cout << "L.size() " << L.size() << endl;
  copy(L.begin(),L.end(), out);
  cout << endl;
  */
  return 0;
}

