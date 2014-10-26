/**
 * @file MedianNumberInTwoArray.cc
 * @brief output the medium number of two sorted array A and B
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-17
 */

#include <bits/stdc++.h>
using namespace std;

int helper(int A[], int m , int B[], int n, int k)
{
  assert(k > 0 );
  if (m > n)
  {
    return helper(B,n,A,m,k);
  }
  //m < n
  if (m == 0) return B[k-1];
  if( k == 1) return min(A[0],B[0]);
  //if (n == 0) return A[k-1];
  int pa = min(k/2, m);
  
  int pb = k - pa;
  cout << pa << " " << pb << endl;
  cout << A[pa-1] << " " << B[pb-1] << endl;

  if(A[pa-1]== B[pb-1])  return A[pa-1];

  else if(A[pa-1] > B[pb-1])
    return helper(A,m,B+pb,n-pb,k-pb);
  else
    return helper(A+pa,m-pa,B,n,k-pa);
}

int findMedium(int A[], int B[], int m, int n)
{
  //odd count
  if((m+n) & 0x01)
  {
    cout << m << " " << n << " is odd..." << endl;
    return helper(A,m,B,n,(m+n)/2+1);
    //return helper(A,m,B,n,1);
  }
  //even count
  else
  {
    cout << m << " " << n << " is even..." << endl;
    return (helper(A,m,B,n,(m+n)/2) + helper(A,m,B,n,(m+n)/2+1))/2;
  }
}

int main()
{
  int B[] = {1,2,3,4};
  int A[] = {4,5,6};
  int m = sizeof(A)/sizeof(int);
  int n = sizeof(B)/sizeof(int);
  cout << "medium : " << findMedium(A,B,m,n) << endl;
  return 0;
}
