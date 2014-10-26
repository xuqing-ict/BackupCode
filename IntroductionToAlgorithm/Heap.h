// Last Update:2014-07-26 18:01:54
/**
 * @file Heap.h
 * @brief heap 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-26
 */

#ifndef _HEAP_H
#define _HEAP_H

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>  Elem;

struct cmp:public binary_function<const Elem &, const Elem & ,bool>
{
  bool operator()(const Elem &lhs, const Elem &rhs)
  {
      return lhs.second > rhs.second;
  }
};

class Heap
{
  private:
    vector<Elem> content;
    
  public:
    Heap(){}
    template<class InputIterator>
    Heap(InputIterator beg, InputIterator end)
    {
      content.assign(beg,end);
      make_heap(content.begin(), content.end(), cmp());
    }

    void push(const Elem &x)
    {
      content.push_back(x);
      push_heap(content.begin(),content.end(),cmp());
    }
    void pop()
    {
      pop_heap(content.begin(),content.end(),cmp());
      content.pop_back();
    }
    void decreaseKey(int key, int value)
    {
      auto idx = find_if(content.begin(), content.end(), [& key](const Elem & x){return key==x.first;});
      if(idx==content.end())
      {
        cout << "error : input illegal!!" << endl;
        return;
      }
      if((*idx).second <= value) 
      {
        return;
      }
      (*idx).second=value;
      push_heap(content.begin(), idx+1,cmp());
    }
    bool empty() const
    {
      return content.empty();
    }
    Elem min() const
    {
        if(empty())
            throw runtime_error("empty heap...");

      return content[0];
    }
};

#endif  /*_HEAP_H*/
