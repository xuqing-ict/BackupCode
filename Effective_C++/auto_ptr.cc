/**
 * @file Auto_ptr.cc
 * @brief Implement an auto ptr
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Auto_ptr
{
private:
    T *pointee;
public:
   Auto_ptr(T *ptr=0):pointee(ptr){}
   ~Auto_ptr(){delete pointee;}
   Auto_ptr<T> &operator=(Auto_ptr<T> &rhs)
   {
      if(this==&rhs) return *this;
      delete pointee;
      pointee = rhs.pointee;
      rhs.pointee = nullptr;
      return *this;
   }
   //copy ctor
  Auto_ptr(Auto_ptr<T> &rhs)
  {
    pointee = rhs.pointee;
    rhs.pointee = nullptr;
  }
  //operator *
  Auto_ptr<T> &operator*()
  {
      return *pointee;
  }
  //operator->
  T *operator->()
  {
      return pointee;
  }
};
template<class T>
void f(Auto_ptr<T> rhs)
{
    cout << "Error!!" << endl;
    return;
}
int main(void)
{
    Auto_ptr<int> p1(new int(10));
    Auto_ptr<int> p2 = p1;
    Auto_ptr<int> p3(p2);
    p1 = p3;
    f(p3); 
	vector<auto_ptr<int> > vec;
	//auto_ptr<int> p(new int(1));
	vec.push_back(auto_ptr<int>(new int(1)));
    return 0;
}
