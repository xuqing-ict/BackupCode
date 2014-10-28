/**
 * @file exception.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-28
 */

//throw the exception in member initialized list
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class A
{
private:
  int x;
public:
  A(int _x=0);
};
A::A(int _x) try{:x(3/_x) }
  catch(...)
  {
    cout << "exception catched..." << endl;
    exit(1);
  }
  {
      cout << "ctor called..." << endl;
  }


int main(void)
{
  A a;
  return 0;
}
