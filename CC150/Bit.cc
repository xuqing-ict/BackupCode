/**
 * @file Bit.cc
 * @brief Bit operation
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-24
 */

#include <bits/stdc++.h>
using namespace std;
void print(int M)
{
  for(int i = sizeof(int)*8-1; i >= 0 ; --i)
  {
    if(M & (1<<i)) cout << 1;
    else cout << 0;
  }
}
int count(int M)
{
  if(M ==0 || M == 1 ) return 1;
  int l = count(M>>1);
  return l+1;
}
//method 1
void func1(int M, int N, int left, int right)
{
  cout << "M : " << endl; print(M);cout << endl;
  cout << "N : " << endl; print(N);cout << endl;
  int size = count(N);
  cout << size << endl;
  for(int k=size-1; k>=0 ; --k)
  {
    assert(left-k>=0);
    M = ((N&(1<<k))<<(left-k))|M;
    cout << "step " << k << " : ";
    cout << "M = "; print(M);cout << endl;
    --left;
  } 
}
//method 2
void func1_2(int M, int N, int left, int right)
{
  int mask = 1;
  for(int i=left;i>right;--i)
  {
    mask = (mask<<1)+1;
  }
  print(mask);cout << endl;
  cout <<"mask :" <<  mask << endl;
  mask <<= right;
  mask = ~mask;
 cout << "mask : "; print(mask);cout << endl;
  cout << "M : " ;print(M);cout << endl;
  M = M & mask;
  cout << "M : " ;print(M);cout << endl;
  
  M = M | (N <<right);
  print(N<<right);cout << endl;
  print(M);cout << endl;
}
//answer
void func1_3(int n, int m ,int i, int j)
{
  int allones = ~0;
  int left = allones<<(j+1);
  int right = (1<<i)-1;
  int mask = left | right;
  cout << "left : ";print(left);cout << endl;
  cout << "right: ";print(right);cout << endl;
  cout << "mask: ";print(mask);cout << endl;
  int n_cleared = n & mask;
  int m_shifted = m << i;
  cout << n_cleared | m_shifted << endl;
}
int main()
{
  print(8);cout << endl;
  cout << " 8 bit count = " << count(8) << endl;
  cout << " 9 bit count = " << count(9) << endl;
  func1_2((1<<10),19,6,2);
  func1_3((1<<10),19,2,6);
  return 0;
}
