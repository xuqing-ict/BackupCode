/**
 * @file quickSort.cc
 * @brief quick sort
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-30
 */

#include <bits/stdc++.h>
using namespace std;

void quickSort(int A[], int left, int right)
{
  if (left >= right) return;
  int i=left, j=right-1;
  int pivot=A[right];
  while(i <= j )
  {
      while(i <= right && A[i] < pivot) ++i;
      while(j >= left && A[j] > pivot) --j;
      if(i <=j)
      {
          swap(A[i],A[j]);
          ++i;--j;
      }
  }
  swap(A[i], A[right]);
  quickSort(A, left,j);
  quickSort(A, i+1, right);
}

int main(void)
{
    srand(time(NULL));
    int n;
    n = rand()%10;
    int *A = new int[n];
    for(int i=0;i<n;++i)
        A[i]=rand()%10;
    for(int i=0;i<n;++i)
        cout << A[i] << "\t";
    cout << endl;
    quickSort(A,0,n-1);
    for(int i=0;i<n;++i)
        cout << A[i] << "\t";
    cout << endl;
    delete [] A;
    return 0;
}
