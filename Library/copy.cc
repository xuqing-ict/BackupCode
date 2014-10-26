/**
 * @file copy.cc
 * @brief copy and copy_backward
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-18
 */

/*
 *
 *OutputIterator copy_n (InputIterator first, Size n, OutputIterator result);
 */
#include <bits/stdc++.h>
using namespace std;

bool odd(int i)
{
  return i%2;
}

bool (*f)(int) = odd;

class oddClass
{
public:
  oddClass(int x=2) : val(x) {}
  bool operator() (int x)
  {
    return x%val;
  }
private:
  int val;
};

int main()
{
  vector<int> A = {1,2,3,4,5};
  //copy
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  A.resize(A.size()+10);
  copy(A.begin(), A.begin()+5, A.begin()+5);
  cout << A.size() << endl;
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  //copy_backward
  copy_backward(A.begin()+10,A.end(), A.begin()+5);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  //copy_if
  for(int i=0 ; i < A.size();++i)
    A[i]=i;
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  //copy_if(A.begin(), A.end(), A.begin(),[x](int i){return !(i>0);});
  //function name as the third parameter
  copy_if(A.begin(), A.end(), A.begin(),odd);
  //function pointer as the third parameter
  copy_if(A.begin(), A.end(), A.begin(),f);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  //function object as the third parameter
  copy_if(A.begin(), A.end(), A.begin(),oddClass(2));
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
  for(int i=1; i < A.size(); ++i)
    A[i ]=i; 
  copy_n(A.begin(),10, A.begin()+3);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;

  for(int i=1; i < A.size(); ++i)
    A[i]=i; 
  int x = 10;

  int y = 1;
  auto functor = [x, &y] (int i) {
    cout << "y: " << y << endl;
    return i >=x;
  };
  y = 2;

  //copy_if(A.begin(), A.end(), A.begin(),[x](int i){return (i>=x);});
  copy_if(A.begin(), A.end(), A.begin(),functor);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout ,"\t"));
  cout << endl;
}
