/**
 * @file 2533.cc
 * @brief LIS
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-06
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
/*
int LIS(const vector<int> &A)
{
  const int n =A.size();
  vector<int> f(n,1);
  int ret=INT_MIN;
  for(int i=0; i<n; ++i)
  {
    for(int j=0;j<i;++j)
    {
      if(A[i] > A[j] && f[j]+1 > f[i])
          f[i]=f[j]+1;
    }
    ret=max(ret,f[i]);
  }

  return ret;
}
*/
int LIS(const vector<int> &A)
{
    const int n = A.size();
    vector<int> dp(n,INT_MAX);
    for(int i=0; i<n; ++i)
    {
      *(lower_bound(dp.begin(),dp.end(),A[i])) = A[i];
    }
    return lower_bound(dp.begin(),dp.end(),INT_MAX)-dp.begin();
}
int main(void)
{
  int n;
  cin >> n;
  vector<int> A(n,0);
  for(int i=0;i<n;++i)
      cin >> A[i];
  cout << LIS(A) << endl;
  return 0;
}
