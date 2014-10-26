/**
 * @file quickSort.cc
 * @brief quick sort two versions
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

int partition(int *A,int left, int right)
{
  int pivot = A[right];
  int j = left; //the first >= pivot position
  for(int i = left; i < right;++i)
  {
    if(A[i] < pivot) swap(A[i],A[j++]);
  }
  swap(A[j], A[right]);
  return j;
}

void quickSort(int *A, int left, int right)
{
  if(left < right)
  {
    int i = partition(A, left, right);
    quickSort(A, left,i-1);
    quickSort(A,i+1,right);
  }
}

int main()
{
  int all=0,count=0;

  cin >> all;
  for(int j = 0 ; j< all; ++j)
  {
    cin >> count;
    int *A = new int[count];
    for(int i = 0; i < count;++i)
      cin >> A[i];
    quickSort(A,0,count-1);
    for(int i = 0 ; i< count;++i)
      cout << A[i] << " ";
    cout << endl;
    delete [] A;
  }
  return 0;
}
