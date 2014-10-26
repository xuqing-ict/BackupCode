// Last Update:2014-06-11 21:18:15
/**
 * @file setStacks.h
 * @brief  a set of stacks
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-11
 */

#ifndef SET_STACKS_H
#define SET_STACKS_H

#include <bits/stdc++.h>
using namespace std;

struct Stack
{
  stack<int> s;
  int size;
  int index;
  Stack():size(0), index(0){}
  Stack(int value, int _index)
  {
    s.push(value);
    size = 1;
    index = _index;
  }
};

class SetofStack
{
private:
  const static int MAXSIZE = 4;
  vector<Stack> vs;
  int count;
public:
  SetofStack():count(0){}
  void push(const int value);
  void pop() ;
  int top() ;
  bool empty() const;
  void popAt(int index);
  int get_count() const;
};
int SetofStack::get_count() const
{
  return count;
}
void SetofStack::push(const int value) 
{
  if(vs.empty() || vs.back().size == MAXSIZE)
  {
    Stack s(value,count);
    vs.push_back(s);
    ++count;
    return;
  }
  vs.back().s.push(value);
  vs.back().size++;
}
bool SetofStack::empty() const
{
  return (count == 0);
}
void SetofStack::pop()
{
  if(empty()|| vs.back().s.empty())
  {
    throw range_error("stack is empty!!!");
  }

  vs.back().s.pop();
  vs.back().size--;
  if(vs.back().size==0)
  {
    vs.pop_back();
    --count;
  }
}
  
int SetofStack::top()
{
  if(empty())
  {
    throw range_error("stack is empty!!!");
  }
  if(vs.back().s.empty())
  {
    vs.pop_back();
    --count;
  }
  return vs.back().s.top();
}

void SetofStack::popAt(int index)
{
  assert(index <= count); 
  if(vs[index].s.empty())
  {
    throw range_error("stack is empty!!! popAt error!!!");
  }
  vs[index].s.pop();
  vs[index].size--;
}
#endif  /*SET_STACKS_H*/
