/**
 * @file maxIJ.cc
 * @brief max (j-i) which satisfy A[i]<A[j]
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-10
 */

#include <bits/stdc++.h>
using namespace std;

int maxIJ1(const vector<int> &A)
{
  const int n = A.size();
  if(n<2) return -1;
  int maxdiff=0;
  for(int i=0; i<n; ++i)
  {
    for(int j=n-1;j>i;--j)
    {
      //maxdiff=max(maxdiff,j-i);
      if((A[j]>A[i]) && (j-i)>maxdiff)
      {
        maxdiff=j-i;
        break;
      }
    }
  }
  return maxdiff;
}

int maxIJ2(const vector<int> &A)
{
  const int n = A.size();
  if(n<2) return -1;
  typedef pair<int,int> P;
  vector<P> tmp(n);
  for(int i=0;i<n;++i)
    tmp[i]=make_pair(A[i],i);
  sort(tmp.begin(), tmp.end());
  //preprocessing the index
  vector<int> rMaxIndex(n,0);
  rMaxIndex[n-1]=tmp[n-1].second;
  for(int i=n-2;i>=0;--i)
      rMaxIndex[i]=max(rMaxIndex[i+1],tmp[i].second);
  int maxdiff=0;
  for(int i=0;i<n;++i)
  {
    int left=tmp[i].second;
    int right=rMaxIndex[i];
    assert(A[left]<=A[right]);
    if(A[left]!=A[right] && (right-left)>maxdiff)
        maxdiff=right-left;
  }
  return maxdiff;
  
}
int maxIJ(const vector<int> &A)
{
  const int n = A.size();
  if(n<2) return -1;
  vector<int> lMin(n,0),rMax(n,0);
  lMin[0]=A[0];
  rMax[n-1]=A[n-1];
  for(int i=1; i<n; ++i)
    lMin[i] = min(lMin[i-1],A[i]);
  for(int i=n-2; i>=0; --i)
    rMax[i] = max(rMax[i+1],A[i]);
  int maxdiff=0;
  int i=0,j=0;
  while(i<n && j<n)
  {
    if(lMin[i]<rMax[j])
    {
      maxdiff=max(maxdiff,j-i);
      j++;
    }
    else
    {
      ++i;
    }
  }
  return maxdiff;
}
int main(void)
{
  srand(time(NULL));
  int n=rand()%100;
  vector<int> A(n,0);
  for(int i=0;i<n;++i)
      A[i]=rand()%100;
  int n1= maxIJ(A);
  int n2=maxIJ1(A);
  int n3=maxIJ2(A);
  cout << n1 << "\t" << n2 << "\t" << n3 << endl;
  assert(n1==n2 && n2 == n3);
  return 0;
}
