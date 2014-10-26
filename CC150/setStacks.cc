/**
 * @file setStacks.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-11
 */
#include "setStacks.h"
int main()
{
  SetofStack sos;
  sos.push(1);
  sos.push(1);
  sos.push(1);
  sos.push(1);
  cout << sos.get_count() << endl;
  //sos.pop(); 
  sos.push(5);
  cout << sos.top() << endl;
  cout << sos.get_count() << endl;
  sos.push(6);
  sos.push(7);
  sos.push(8);
  cout << sos.get_count() << endl;
  sos.push(9);
  cout << sos.top() << endl;
  cout << sos.get_count() << endl;
  //sos.popAt(2);
  sos.popAt(2);
  cout << "pop at end..." << endl;
  cout << sos.top() << endl;
  return 0;
}
