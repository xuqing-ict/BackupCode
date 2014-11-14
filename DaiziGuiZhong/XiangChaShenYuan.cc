/**
 * @file XiangChaShenYuan.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-03
 */
/*给定一个数组，我们可以找到两个不相交的、并且是连续的子数组A和B，A中的数字和为sum(A), B中的元素和为sum(B)。找到这样的A和B，满足sum(A) - sum(B)的绝对值是最大的。 例如：[2, -1 -2, 1, -4, 2, 8]划分为A=[-1, -2, 1, -4], B=[2, 8]， 最大的值为16*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void minSub(const vector<int> &A, vector<int> &minL, vector<int> &minR, vector<int> &maxL, vector<int> &maxR)
{
  //compute minL and maxL
  const int n = A.size();
  vector<int> minLocal(n,0), maxLocal(n,0);
  minLocal[0]=A[0];
  maxLocal[0]=A[0];
  //minL[0]=min(0,A[0]);
  //maxL[0]=max(0,A[0]);
  minL[0]=A[0];
  maxL[0]=A[0];
  for(int i=1;i<n;++i)
  {
      minLocal[i] = min(minLocal[i-1]+A[i], A[i]);
      minL[i] = min(minL[i-1],minLocal[i]);
      maxLocal[i] = max(maxLocal[i-1]+A[i], A[i]);
      maxL[i] = max(maxL[i-1],maxLocal[i]);
  }
  minLocal[n-1]=A[n-1];
  maxLocal[n-1]=A[n-1];
  //minR[n-1]=min(0,A[n-1]);
  //maxR[n-1]=max(0,A[n-1]);
  minR[n-1]=A[n-1];
  maxR[n-1]=A[n-1];

  for(int i=n-2;i>=0;--i)
  {
      minLocal[i] = min(minLocal[i+1]+A[i], A[i]);
      minR[i] = min(minR[i+1],minLocal[i]);
      maxLocal[i] = max(maxLocal[i+1]+A[i], A[i]);
      maxR[i] = max(maxR[i+1],maxLocal[i]);
  }
  cout << "minL : " ;
  for(int i=0;i<n;++i) cout << minL[i] << "\t";
  cout << endl;
  cout << "maxL : " ;
  for(int i=0;i<n;++i) cout << maxL[i] << "\t";
  cout << endl;
  cout << "minR : " ;
  for(int i=0;i<n;++i) cout << minR[i] << "\t";
  cout << endl;
  cout << "maxR : " ;
  for(int i=0;i<n;++i) cout << maxR[i] << "\t";
  cout << endl;
}

int diff(const vector<int> &A)
{
  const int n = A.size();
  vector<int> minL(n,0);
  vector<int> maxL(n,0);
  vector<int> minR(n,0);
  vector<int> maxR(n,0);
  minSub(A,minL,minR,maxL,maxR);
  int ret = 0;
  for(int i=1;i<n;++i)
  {
      int s1=abs(minL[i-1]-maxR[i]);
      int s2=abs(maxL[i-1]-minR[i]);
      if(s1 > ret) ret = s1;
      if(s2 > ret) ret = s2;
  }
  return ret;
}
int main(void)
{
 // vector<int> A = {2,-1,-2,1,-4,2,8};
  vector<int> A = {-1,-1,1,2,-1,-2};
  cout << diff(A) << endl;
  return 0;
}
