/**
 * @file quickSort.cc
 * @brief quick sort iterativelly
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-09
 */

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int left, int right)
{
  int pivot=A[right];
  int i=left;
  for(int k=left;k<right;++k)
  {
    if (A[k] < pivot) swap(A[i++],A[k]);
  }
  swap(A[i],A[right]);
  return i;
}

void quickSort(vector<int> &A)
{
    stack<pair<int,int> > s;
    const int n = A.size();
    if(n <2 ) return;
    int left=0,right=n-1;
    s.push(make_pair(left, right));
    while(!s.empty())
    {
      auto cur=s.top();s.pop();
      left=cur.first;right=cur.second;
      if(left>=right)continue;
      int mid=partition(A,left,right);
      s.push(make_pair(left, mid-1));
      s.push(make_pair(mid+1, right));
    }
}

void merge(vector<int> &A, int left, int mid, int right)
{
  int i=left,j=mid+1;
  vector<int> tmp(right-left+1,0);
  int k=0;
  while(i<=mid&&j<=right)
  {
    if(A[i] < A[j]) tmp[k++]=A[i++];
    else tmp[k++]=A[j++];
  }
  while(i<=mid)tmp[k++]=A[i++];
  while(j<=right)tmp[k++]=A[j++];
  //write to A
  for(int i=0;i<right-left+1;++i)
  {
    A[left+i]=tmp[i];
  }
}
void mergeSort(vector<int> &A)
{
    const int n=A.size();
    int step=1;
    int left=0,right,mid;
    while(step< n)
    {
      left=0;
      while(left+step<n)
      {
        mid=left+step-1;
        right=mid+step;
        if(right>=n) right=n-1;
        merge(A,left,mid,right); 
        left=right+1;
      }
      step *= 2;
    }
}

int main(void)
{
    
  srand(time(NULL));
  int n = rand()%20;

  vector<int> A(n,0);
  for(int i=0;i<n;++i)
      A[i]=rand()%30;
  for(auto a:A)
      cout << a << "\t";
  cout << endl;
  //quickSort(A);
  mergeSort(A);
  for(auto a:A)
      cout << a << "\t";
  cout << endl;
  return 0;
}
