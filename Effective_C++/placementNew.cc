/**
 * @file placementNew.cc
 * @brief placement new
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */

#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
  int x;
public:
  //会掩盖正常的operator new
  static void *operator new (size_t size, ostream & logStream) throw(bad_alloc)
  {
  }

};
int main()
{
  //Base *pb = new Base();
  Base *pb = new (std::cerr) Base;
  return 0;
}
