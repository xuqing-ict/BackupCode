/**
 * @file shared.cc
 * @brief shared ptr
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;
class Base
{
private:
  int *x;
  int *count;//ref counting
public:
  Base(int _x = 0);
  Base(const Base &rhs);
  Base &operator=(const Base &rhs);
  ~Base();
};
/*
Base::Base(int *_x)
{
  assert(_x != nullptr);
  x = new int(*_x);
  count = new int(1);
}
*/
Base::Base(int _x)
{
  x = new int(_x);
  count = new int(1);
}

Base::Base(const Base &rhs)
{
  x = rhs.x;
  count = rhs.count;
  ++*count;
}

Base &Base::operator=(const Base &rhs)
{
   //self-copy
  /*
  if (this == &rhs) return *this;
  --*count;
  if(*count == 0 )
  {
    delete x;
    delete count;
  }
  x = rhs.x;
  count = rhs.count;
  ++(*count);
  */
  ++(*rhs.count);
  if (--*count == 0)
  {
    delete x;
    delete count;
  }
  x = rhs.x;
  count = rhs.count;
  return *this;
}

Base::~Base()
{
  --(*count);
  if (*count == 0)
  {
    delete count;
    delete x;
  }
}
int main()
{
  Base b(2);
  Base b3(4);
  Base b4 = b3;
  Base b5(b3);
  Base b6;
  return 0;
}
