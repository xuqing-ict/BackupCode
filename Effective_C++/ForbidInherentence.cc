/**
 * @file ForbidInherentence.cc
 * @brief 禁止继承
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-30
 */

#include <bits/stdc++.h>
using namespace std;

class FINAL
{
private:
    FINAL(){ cout << "ctor..." << endl;}
    FINAL(const FINAL &){cout << "copy ctor..." << endl;} 

public:
    static FINAL *makeFINAL()
    {
        return new FINAL();
    }
    static FINAL *makeFINAL(const FINAL &rhs)
    {
        return new FINAL(rhs);
    }
};
class derived:public FINAL
{
  public:
      derived(){}
};
int main()
{
  shared_ptr<FINAL> p1(FINAL::makeFINAL());
  derived d; // error!!! ctor of FINAL is private
  return 0;
}
