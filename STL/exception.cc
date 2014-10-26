/**
 * @file exception.cc
 * @brief exception
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-15
 */

#include <bits/stdc++.h>
using namespace std;

class IllegalNumberException{};
bool isNumber(const char *str)
{
  if (str == nullptr)
  {
      return false;
  }
  while(*str)
  {
    if(!isdigit(*str)) return false;
    ++str;
  }
  return true;
}

int myatoi(const char *str) throw(IllegalNumberException)
{
    if(!isNumber(str))
        throw IllegalNumberException();
    return atoi(str);
}

int main()
{
    string num1, num2;
    try{
    cin >> num1;
    cin >> num2;
    int n1 = myatoi(num1.c_str());
    int n2 = myatoi(num2.c_str());
    cout << n1 + n2 << endl;
    }catch(IllegalNumberException)
    {
        cout << "Illegal input!!!" << endl;
    }
    return 0;
}
