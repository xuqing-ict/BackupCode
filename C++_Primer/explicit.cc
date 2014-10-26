/**
 * @file explicit.cc
 * @brief explicit function
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-09
 */

#include<bits/stdc++.h>
using namespace std;

class A
{
private:
    string s;
  public:
    A(const char *_s):s(_s){}

};
int main()
{
  A a = A("ctor");
  return 0;
}
