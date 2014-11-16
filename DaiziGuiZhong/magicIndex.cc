/**
 * @file magicIndex.cc
 * @brief magic index
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-03
 */

/*给定一个数组A，其中有一个位置被称为Magic Index，含义是：如果i是Magic Index，则A[i] = i。
//假设A中的元素递增有序、且不重复，请给出方法，找到这个Magic Index。更进一步，当A中允许有重复的元素，该怎么办呢？*/
#include <bits/stdc++.h>
using namespace std;

//magic index with no repeat
int magicIndex(const vector<int> &A)
{
  const int n=A.size();
  if(n==0) return -1;
  int left=0,right=n-1;
  while(left <= right)
  {
    int mid=left+(right-left)/2;
    if(A[mid] == mid) return mid;
    else if (A[mid] > mid)right = mid-1;
    else left = mid+1;
  }
  return -1;
}

//magic index with repeat
int binary_search(const vector<int> &A, int left, int right)
{
    int l=-1,r=-1;
  if(left <= right)
  {
    int mid=left+(right-left)/2;
    if(A[mid]==mid) return mid;
    else if(A[mid] < mid)
    {
      l=binary_search(A,left,min(A[mid],mid-1));
      if(l != -1) return l;
      r=binary_search(A,mid+1,right);
    }
    else
    {
      l=binary_search(A,left,mid-1);
      if(l!=-1) return l;
      r=binary_search(A,max(mid+1,A[mid]),right);
    }
  }
  return (l==-1)?r:l;
}

int magicIndexWithRepeat(const vector<int> &A)
{
  const int n = A.size();
  return binary_search(A,0,n-1);
}

int main(void)
{
    vector<int> A = {2,2,2,2,10,12,13,20};
    cout << "magic index = " << magicIndex(A) << endl;
    cout << "magic index = " << magicIndexWithRepeat(A) << endl;
    return 0;
}
