/**
 * @file createVectorObj.cc
 * @brief create obj vector
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-29
 */

#include <bits/stdc++.h>
using namespace std;


class A
{
  public:
      A(int x){cout << "A ctor, x = " << x << endl;}
      A(const A &rhs){cout << "A copy ctor..." << endl;}
};
int main(void)
{
    void *raw= operator new[](4*sizeof(A));
    A *vec=static_cast<A*>(raw);
    for(int i=0;i<4;++i)
    {
      new (&vec[i]) A(i);
    }
    for(int i=0;i<4;++i)
    {
      vec[i].~A();
    }
    operator delete[](raw);
    return 0;
}
