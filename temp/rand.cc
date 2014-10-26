/**
 * @file rand.cc
 * @brief rand test
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-26
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(NULL));
  for(int i = 0 ; i< 5;++i)
  {
    int a = rand()%10;
    cout << a << endl;
  }
  return 0;
}
