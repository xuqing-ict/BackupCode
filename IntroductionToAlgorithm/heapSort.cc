/**
 * @file heapSort.cc
 * @brief heap sort using iteratively max_heapify
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

//incursivelly
void max_heapify(int *A, int i, const int n)
{
  int left = i*2+1;
  int right = i*2+2;
  int largest = i;
  if(left < n && A[left] > A[largest])
    largest = left;
  if(right < n && A[right] > A[largest])
    largest = right;
  if(largest != i)
  {
    swap(A[largest], A[i]);
    max_heapify(A,largest, n);
  }
}
//iteratively 
void max_heapify2(int *A,int i, const int n)
{
  while(i < n)
  {
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left < n && A[left] > A[largest]) largest = left;
    if(right < n && A[right] > A[largest]) largest = right;
    if(largest == i )
      break;
    else
    {
      swap(A[largest], A[i]);
      i = largest;
    }
  }
}
void build_heap(int *A, const int n)
{
  for(int i = n/2 ; i >= 0 ; --i)
    max_heapify2(A,i,n);
}

void heapSort(int *A, const int n)
{
  build_heap(A, n);

  for(int i=0;i<n;++i)
  {
    swap(A[0],A[n-1-i]);
    max_heapify(A,0,n-1-i);
  }
}

int main()
{
  /*srand(time(NULL));
  const int n =  rand()%10 + 1;
  int *A = new int[n];
  for(int i =0 ;  i< n; ++i)
    A[i] = rand()%20;
  for(int i = 0 ; i< n;++i)
    cout << A[i] << " ";
  cout << endl;
  delete [] A;
  */
  int all=0,count = 0 ;
  cin >> all;
  for(int j = 0 ; j< all; ++j)
  {
    cin >> count;
    int *A = new int[count];
    for(int i = 0; i < count;++i)
      cin >> A[i];
    heapSort(A,count);
    for(int i = 0 ; i< count;++i)
      cout << A[i] << " ";
    cout << endl;
    delete [] A;
  }
  return 0;
}
