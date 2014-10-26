// Last Update:2014-08-12 13:20:44
/**
 * @file list.h
 * @brief a simple inmplementation of list
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-12
 */

#ifndef LIST_H
#define LIST_H


template<class T>
struct list_node
{
  list_node<T>* prev;
  list_node<T>* next;
  T data;
};
template<class T>
struct list_iterator
{
    list_node<T>* node;

    //5 iterator type
    typedef T value_type;
    typedef T* pointer;
    typedef ptrdiff_t difference_type;
    typedef T & reference;
    
    //other types
    typedef size_t size_type;
    typedef const T * pointer;
    typedef const T & const_reference;
    typedef list_iterator iterator;
    //ctor
    list_iterator(list_node<T>*p = nullptr):node(p){}

    //operator++ --
    iterator &operator()
    {
      node=node->next;
      return node;
    }
    iterator operator++(int)
    {
      iterator tmp=*this;
      ++*this;
      return tmp;
    }
    iterator &operator--()
    {
      node=node->prev;
      return node;
    }
    iterator operator--(int)
    {
      iterator tmp=*this;
      --*this;
      return tmp;
    }

    //operator==
    bool operator==(const iterator &rhs)
    {
      return node==rhs.node;
    }
    bool operator!=(const iterator &rhs)
    {
      return node!=rhs.node;
    }

    //two important operators: * ->
    //对迭代器取值，取的是节点中元素的值
    reference operator*() const
    {
      return *(node).data;
    }
    pointer operator->() const
    {
      return &operator*();
    }
};

template<class T>
class List
{
//typedef
public:
  typedef T value_type;
  typedef ptrdiff_t  difference_type;
  typedef T & reference;
  typedef T* pointer;
  typedef list_iterator<T> iterator;
  typedef const list_iterator<T> const_iterator;
  typedef size_t size_type;
private:
    list_node<T> * node;
    typedef simple_alloc<list_node, alloc> list_node_allocator;
public:
    //ctor
    List():node(nullptr){}
    
    template<class InputIterator>
    List(InputIterator first, InputIterator last);

    List(size_type n, const T &val);

    iterator begin(){return node->next;}
    iterator end(){return node;}
  
    //allocate
    
};
template<class InputIterator>
List(InputIterator first, InputIterator last)
{
  while(first!=last)
  {
       
  }
}
List::List()
#endif  /*LIST_H*/
