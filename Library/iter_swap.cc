/**
 * @file iter_swap.cc
 * @brief iter_swap
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-18
 */

/*
 * iter_swap(forwardIterator1 a, forwardIterator2 b)
 * swap the content of iterator, not the iterator itself
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> A = {1,2,3,4,5};
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  //iter_swap(A.begin(), --A.end());
  iter_swap(A.begin(), ++A.begin());
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  return 0;
}
