/**
 * @file string.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-27
 */

//Test the member function of string
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  string s = "Hello";
  cout << s.c_str() << endl;
  cout << s.data() << endl;
  return 0;
}
