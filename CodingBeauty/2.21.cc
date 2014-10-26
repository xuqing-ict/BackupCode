/**
 * @file 2.21.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-13
 */

//只考加法的面试题
#include <bits/stdc++.h>
using namespace std;

const double ZERO = 0.000001;

void print(const long long N)
{
  long long j;
  j=(sqrt(8*N-1)+1)/2;
  cout << "j : " << j << endl;

  for(long long i=1;i<=j;++i)
  {
    double a=static_cast<double>(N)/(i+1)-static_cast<double>(i)/2;
    double temp=a-(long long)a;
    if(temp < ZERO && a > ZERO)
    {
      cout << N <<  " = " ;
      for(int k=0;k<=i;++k)
      {
        cout << static_cast<long long>(a+k) << "\t";
      }
      cout << endl;
    }
  }
}
int main(void)
{
  long long N;
  cin >> N;
  print(N);
  return 0;
}
