/**
 * @file twoQueueAsOneStack.cc
 * @brief two queues as a stack
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
class MyStack
{
private:
  queue<T> queue1;
  queue<T> queue2;
public:
  MyStack(){}
  ~MyStack(){}
  bool empty() const {return queue1.empty() && queue2.empty();}
  void push(const T & x);
  void pop();
  T top() ;
};
template<class T>
void MyStack<T>::push(const T &x)
{
  //if both empty, both ok
  if(queue1.empty()) queue2.push(x);
  else queue1.push(x);
}

template<class T>
void MyStack<T>::pop()
{
  if(empty()) throw runtime_error("empty stack!!!");
  if(queue1.empty()) queue1.swap(queue2);
  assert(!queue1.empty()&&queue2.empty());
  while(!queue1.empty())
  {
    T x = queue1.front();
    queue1.pop();
    if(queue1.empty())
      return;
    queue2.push(x);
  }
}

template<class T>
T MyStack<T>::top()
{
  if(empty()) throw runtime_error("empty stack!!!");
  if(queue1.empty()) queue1.swap(queue2);
  assert(!queue1.empty()&&queue2.empty());
  T x;
  while(!queue1.empty())
  {
    x = queue1.front();
    queue2.push(x);
    queue1.pop();
  }
  return x;
}

int main()
{
  MyStack<int> s;
  s.push(3);
  s.push(2);
  s.push(1);
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  assert(s.empty());
  return 0;
}
