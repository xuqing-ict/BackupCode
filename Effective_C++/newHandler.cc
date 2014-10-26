/**
 * @file newHandler.cc
 * @brief set new handler
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

void outOfMem2()
{
  cerr << "Unable to allocate2 ..." << endl;
  std::abort();
}
void outOfMem()
{
  cerr << "Unable to allocate..." << endl;
  std::abort();
}
int main()
{
  //std::set_new_handler(outOfMem);
  std::set_new_handler(NULL);
  int *pBigData =  new int[1000000000000000L];
  delete [] pBigData;
  return 0;
}

