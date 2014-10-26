/**
 * @file Coin.cc
 * @brief minimum coin
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-13
 */

#include <bits/stdc++.h>
using namespace std;

const int V[6] = {500,100,50,10,5,1};
const int C[6] = {1,2,3,4,5,4};
int minCoins(const int sum)
{
  int ret=0;
  int temp = sum;
  for(int i=0;i<6;++i)
  {
    int t = min(temp/V[i],C[i]);
    temp -= (t*V[i]);
    ret += t;
  }
  return ret;
}
int main()
{
  int sum;
  cin >> sum;
  cout << minCoins(sum) << endl;
  return 0;
}
