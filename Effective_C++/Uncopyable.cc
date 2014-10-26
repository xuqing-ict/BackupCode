/**
 * @file Uncopyable.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-12
 */

#include <bits/stdc++.h>
using namespace std;

class UncopyableBase
{ 
protected:
  UncopyableBase(){}
  ~UncopyableBase(){}
private:
  UncopyableBase &operator=(const UncopyableBase &);
  UncopyableBase(const UncopyableBase &);

};

//UncopyableBase is a empty class.
//OneCopy derivec UncopyableBase private.
class OneCopy:private UncopyableBase
{
private:
  int index;
  string name;
public:
  OneCopy(){}
  ~OneCopy(){}
  //OneCopy no need to declare the two functions
//  OneCopy &operator=(const OneCopy &);
  //OneCopy(const OneCopy &);
};
int main()
{
  OneCopy one;
  OneCopy two(one);
  OneCopy three;
 // three = one;
  return 0;
}
