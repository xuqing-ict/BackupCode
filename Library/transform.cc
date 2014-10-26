/**
 * @file transform.cc
 * @brief transform // the second parameter would be a function or a functor 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-17
 */

#include <bits/stdc++.h>
using namespace std;

int func(int x)
{
  return x*x;
}
//func
class Func
{
public:
  int operator() (int x) //operator() override
  {
    return x*x*x;
  }
};
int main()
{
  vector<int> A = {1,2,3,4};
  transform(A.begin(), A.end(), A.begin(), Func());
  copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
  cout << endl;
  int A2[] = {5,6,7,8};
  int n = sizeof(A2)/sizeof(int);
  transform(A2, A2+n, A2, func);
  copy(A2,A2+n, ostream_iterator<int>(cout,"\t"));
  cout << endl;
  return 0;
}
