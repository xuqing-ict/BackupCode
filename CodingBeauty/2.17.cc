/**
 * @file 2.17.cc
 * @brief shift the array
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-07
 */
#include <bits/stdc++.h>
using namespace std;

void shiftReverse(string &s, int K)
{
    if(s.empty() || K == 0) return;
    const int N = s.size();
    if(K < 0) K=N-K;
    K %= N;
    reverse(s.begin(),s.begin()+(N-K));
    reverse(s.begin()+N-K,s.end());
    reverse(s.begin(),s.end());
}

int main(void)
{
  string s = "1234abcd";
  int K = -11;
  shiftReverse(s,K);
  cout << s << endl;
  return 0;
}

