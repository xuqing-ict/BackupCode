/**
 * @file findInsertPos.cc
 * @brief find insertion position of target in a sorted array with no duplicates
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-20
 */

#include <bits/stdc++.h>
using namespace std;

int findPosition(int A[], int left, int right, const int target)
{
  while(left <= right)
  {
    int mid = left + (right-mid)/2;
    if (A[mid] < target) left = mid+1;
    else right = mid-1;
  }
  return left;
}
int* lower_bound(int A[], int n, const int target)
{
  //[first, last)
  int *first = A, *last = A + n;
  while(first != last)
  {
    int *mid = first + (last-first)/2;
    if(*mid < target) first = mid+1;
    else last = mid-1;
  }
  return first;
}

int main()
{
  int A[] = {1,3,4,5,6};
  int n = sizeof(A)/sizeof(int);
  int target = 2;
  cout << findPosition(A,0, n-1 , target) << endl;
  cout << lower_bound(A,n,target)-A << endl;
  vector<int> B(5,0);
  for(auto it = begin(B); it != end(B); ++it)
    *it = 3;
  for(auto a: B)
    cout << a << " ";
  cout << endl;
  return 0;
}
