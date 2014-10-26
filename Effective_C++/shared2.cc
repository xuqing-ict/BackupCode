/**
 * @file shared2.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

class Base {
public:
  Base(int x=0): val_(make_shared<int>(x)) {
  }
  //copy control no need
private:
  shared_ptr<int> val_;
};

int main(void)
{
  Base b(2);
  Base b3(4);
  Base b4 = b3;
  Base b5(b3);
  Base b6;
  return 0;
}
