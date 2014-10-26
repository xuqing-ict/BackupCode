// Last Update:2014-08-06 21:19:03
/**
 * @file 1050.cpp
 * @brief To the max 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-06
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int helper(const vector<int> &A)
{
  const int n= A.size();
  int global=A[0], local=0;
  for(int i=0;i<n;++i)
  {
    if(local <=0) local=0;
    local+=A[i];
    if(local > global) global=local;
  }
  return global;
}
int maxSub(const vector<vector<int> >  &A)
{
  const int n = A.size();
  vector<vector<int> > sum(n+1,vector<int>(n+1,0));

  for(int i=1;i<n+1;++i)
      for(int j=1;j<n+1;++j)
          sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + A[i-1][j-1];

  int ret=INT_MIN;
  vector<int> tmp(n+1,0);
  for(int i=1;i<=n;++i)
  {
      for(int j=i;j<=n;++j)
      {
        //enumerate each array
        for(int k=1;k<=n;++k)
          tmp[k] = sum[j][k]-sum[j][k-1]-sum[i-1][k] + sum[i-1][k-1];
        ret=max(ret,helper(tmp));
      }
  }
  return ret;
}
int main(void)
{
  int n;
  cin >> n;
  vector<vector<int> > A(n,vector<int>(n,0));
  for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
          cin >> A[i][j];
  cout << maxSub(A) << endl;
  return 0;
}
