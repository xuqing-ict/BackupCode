/**
 * @file traits.cc
 * @brief traits
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-17
 */

#include <bits/stdc++.h>
using namespace std;

namespace xq
{

struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag : public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};

struct B {};
struct D1 : public B {};
struct D2 : public B {};

template<class T>
void func(T &p, B)
{
    cout << "B version..." << endl;
}
template<class T>
void func(T &p, D2)
{
    cout << "D2 version..." << endl;
}
template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag)
{
  typename std::iterator_traits<InputIterator>::difference_type n = 0;
  cout << "input version..." << endl;
  while(first != last)
  {
      ++first; ++n;
  }
  return n;
}
template<class RandomIterator>
inline typename iterator_traits<RandomIterator>::difference_type
__distance(RandomIterator first, RandomIterator last, random_access_iterator_tag)
{
    cout << "Random version..." << endl;
    return last-first;
}


template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type 
distance(InputIterator first, InputIterator last)
{
  typedef typename iterator_traits<InputIterator>::iterator_category category;
  __distance(first, last, category(first));
}

int main()
{
    int *p;
    func(p,B());
    func(p,D1());
    func(p,D2());
    using std::iterator_traits;
    vector<int> A = {1,2,3,4,5};
    cout << xq::distance(A.begin(), A.begin()+3) << endl;
    return 0;
}
};
