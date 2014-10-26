/**
 * @file not.cc
 * @brief not1 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-16
 */
#include <bits/stdc++.h>
using namespace std;
namespace xq
{
struct isEven
{
    bool operator() (const int x) const {return !(x&1);}
    typedef int argument_type;

};
template<typename InputIterator, typename OutputIterator, typename pred>
OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator dest, pred p)
{
  while(first != last)
  {
    if(p(*first)) *dest++ = *first;
    ++first;
  }
  return dest;
}
}
int main()
{
  vector<int> A = {1,2,3,4,5};
  vector<int> B;
  B.resize(5);//reserve 是不对的！！！
  xq::copy_if(A.begin(), A.end(), B.begin(), not1(xq::isEven()));
  for(int i=0;i<B.size();++i)
      cout << B[i] << " ";
  cout << endl;
  return 0;
}
