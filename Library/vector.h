// Last Update:2014-06-19 17:30:40
/**
 * @file vector.h
 * @brief vector.h
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-19
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>
template<class T>
class myVector
{
  typedef T value_type;
  typedef T* iterator;
  typedef const T * const_iterator;
  typedef T * pointer;
  typedef const T * const_pointer;
  typedef T & reference;
  typedef const T & const_reference;
  typedef size_t size_type;

  //ctor
  myVector();
  myVector(size_type n, const T& value);
  myVector(iterator *beg, iterator *end);
  
  //dtor
  ~myVector();

  //iterator operation
  iterator begin() {return start;}
  iterator end() {return finish;}

  //size or capacity
  size_type size() {return finish-start;}
  size_type capacity() {return end_of_storage-start;}

  //insert
  iterator *insert(iterator *pos, const T & value);

  //push_back and pop_back
  void push_back(const T& value);
  void pop_back();

private:
  iterator start;
  iterator finish;//the end of data
  iterator end_of_storage; //the end of storage
};

template<class T>
myVector::myVector():start(0), finish(0), end_of_storage(0)
{
  //to do
}

template<class T> 
myVector::myVector(size_type n, const T & value):start(0), finish(0), end_of_storage(0)
{
  if(n <= 0 ) return;
  if(n < 0) 
  {
    throw runtime_error("Illegal input parameter!!!");
  }
  
}
#endif  /*VECTOR_H*/
