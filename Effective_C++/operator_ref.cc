/**
 * @file operator_ref.cc
 * @brief why operator= return a reference to this
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-16
 */

#include <bits/stdc++.h>
using namespace std;
class A
{
  friend ostream &operator<<(ostream &out, const A &rhs);
  friend istream &operator>>(istream &out, A &rhs);
  private:
    int x;
  public:
    A(int _x):x(_x){}
    A(){}
    A operator=(const A &rhs)
    {
      x = rhs.x;
      return *this;
    }
};

ostream &operator<<(ostream &out, const A &rhs)
{
  out << rhs.x;
  return out;
}

istream &operator>>(istream &in, A &rhs)
{
  int temp;
  cin >> temp;
  if(in)
  {
    rhs.x = temp;
  }
  else
  {
    rhs = A(-1);
  }
  return in;
}
int main()
{
  A a(1);
  A b(2);
  A c(3);
  A d;
  cin >> d;
  cout << "a : " << a << endl;
  cout << "b : " << b << endl;
  cout << "c : " << c << endl;
  cout << "d : " << d << endl;
  cout << "c = a = b" << endl;

  c = a = b;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}
