/**
 * @file twoStackAsOneQueue.cc
 * @brief two stacks as the queue
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */
#include <bits/stdc++.h>
using namespace std;

template<class T>
class myQueue
{
private:
  stack<T> push_stack;
  stack<T> pop_stack;
public:
  myQueue(){}
  ~myQueue(){}
  bool empty() const{return push_stack.empty() && pop_stack.empty();}
  void push(const T &x);
  void pop();
  T front(); //front is not a const function !!!
};

template<class T>
void myQueue<T>::push(const T& x)
{
  push_stack.push(x);
}

template<class T>
void myQueue<T>::pop()
{
  if(empty()) throw runtime_error("empty queue!!!");
  if(pop_stack.empty())
  {
    while(!push_stack.empty())
    {
      T x = push_stack.top();
      push_stack.pop();
      if(push_stack.empty())
        return;
      pop_stack.push(x);
    }
  }
  else
  {
    pop_stack.pop();
  }
}

template<class T>
T myQueue<T>::front() 
{
  if(empty()) throw runtime_error("empty queue!!!");
  if(pop_stack.empty())
  {
    while(!push_stack.empty())
    {
      T x = push_stack.top();
      push_stack.pop();
      pop_stack.push(x);
    }
  }
  return pop_stack.top();
}


int main()
{
  myQueue<int> q;
  q.push(3);
  q.push(2);
  q.push(1);
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
  q.pop();
  q.pop();
  assert(q.empty());
  return 0;

}
