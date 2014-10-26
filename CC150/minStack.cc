/**
 * @file minStack.cc
 * @brief minStack main 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-11
 */
#include "minStack.h"

int main()
{

  cout << "enter main..." << endl;

  minStack ms ;
  ms.push(1);
  ms.push(-1);
  ms.push(2);
  cout << "min : " << ms.min() << endl;
  cout << "top : " << ms.top() << endl;
  ms.pop();
  ms.pop();
  cout << "top : " << ms.top() << endl;
  if(!ms.empty())
  {
    cout << "ms is not empty..." << endl;
  }
  return 0;
}
