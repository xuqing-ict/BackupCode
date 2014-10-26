/**
 * @file isPalinNumber.cc
 * @brief a number is palin
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-14
 */
#include <bits/stdc++.h>
using namespace std;

bool isPalin(int x)
{
  if(x < 0) return false;
  int base = 1, i = 0;
  for(;  i <= 10; ++i)
  {
    if(x/base == 0) break;
    base *= 10;
  }
  cout << "digits = " << i << endl;
  if (i < 2) return true;
  int base1 = pow(10,i-1);
  int base2 = 1;
  while(base1 > base2)
  {
    if((x/base1)%10 != (x/base2)%10) return false;
    base1/=10;
    base2*=10;
  }
  return true;
}
int main()
{
  int number = 0;
  cin >> number;
  cout << isPalin(number) << endl;
  return 0;
}
