// Last Update:2014-06-11 20:21:46
/**
 * @file minStack.h
 * @brief stack with minimum value
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-11
 */

#ifndef MIN_STACK_H
#define MIN_STACK_H

#include <bits/stdc++.h>
using namespace std;

class minStack
{
private:
  stack<int> s;
  stack<int> minS;//用于保存当前的最小值，不需要保存每一步的最小值！！！
public:
  minStack();
  void push(const int value);
  void pop();
  int min() const;
  int top() const;
  bool empty() const;
};

minStack::minStack()
{
  //to do
}

void minStack::push(const int value)
{
  s.push(value);
  //update new min
  if (minS.empty())
  {
    minS.push(value);
    return;
  }
  if(value < minS.top())
  {
    minS.push(value);
  }
}
int minStack::top() const
{
  return s.top();
}
void minStack::pop()
{
  if(minS.top() == s.top())
  {
    minS.pop();
  }
  s.pop();
}
int minStack::min() const
{
  if(s.empty())
  {
    throw range_error("stack is empty!!!");
  }
  return minS.top();
}
bool minStack::empty() const
{
  return s.empty();
}
#endif  /*MIN_STACK_H*/
