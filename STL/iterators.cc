/**
 * @file iterators.cc
 * @brief iterator traits backup
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-09
 */

#include <bits/stdc++.h>
using namespace std;

struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag : public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};

//Base class for iterator class
template <class Category, class T, class Distance=ptrdiff_t, class Pointer = T*, class Reference =T&>
struct iterator
{
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

template<class T>
struct iterator_traits<T*>
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T & reference;
};

template<class T>
struct iterator_traits<const T*>
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T & reference;
    
};

template<class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
  typedef typename iterator_traits<Iterator>::iterator_category category;
  return category(); //random_access_iterator_tag or bidirectional_iterator_tag ...
}

//pointer to the difference_type
template< class Iterator>
inline typename iterator_traits<Iterator>::difference_type*
distance_type (const Iterator &)
{
  return static_cast<typename iterator_traits<Iterator>::difference_type *>(0);
}

template< class Iterator>
inline typename iterator_traits<Iterator>::value_type *
distance_type (const Iterator &)
{
  return static_cast<typename iterator_traits<Iterator>::value_type* > (0);
}

//distance function

template<class InputIterator>
inline iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag)
{
  iterator_traits<InputIterator>::difference_type n=0;
  while(first != last)
  {
      ++first;++n;
  }
  return n;
}
template<class RandomIterator>
inline typename iterator_traits<RandomIterator>::difference_type
__distance(RandomIterator first, RandomIterator last, random_access_iterator_tag)
{
    return last-first;
}

//user 
template<class InputIterator>
inline iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return __distance(first,last,category());//category()构造一个临时对象，进行参数推导，决定重载函数。
}
