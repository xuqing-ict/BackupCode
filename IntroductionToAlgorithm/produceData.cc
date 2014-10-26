/**
 * @file produceData.cc
 * @brief produce data
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(NULL));
  ofstream out("data");
  int n ;
  //1000 arrays
  out << 1000 << endl;
  for(int  i = 0 ; i < 1000;++i)
  {
    int n = rand()%100 + 10;
    out << n <<  endl;
    for(int i=0; i < n;++i)
      out << rand()%100 << " ";
    out << endl;
  }
  out.close();
  out.clear();
  return 0;
}
