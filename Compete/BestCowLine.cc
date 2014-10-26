/**
 * @file BestCowLine.cc
 * @brief minimal lexicographic order 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-13
 */

#include <bits/stdc++.h>
using namespace std;

string minOrder(const string &s)
{
  int n = s.size();
  if(n <= 1) return s;
  string ret;
  ret.resize(n);
  int k = 0;
  int left = 0, right = n-1;
  while(left <= right)
  {
    bool l = false, r = false;
    int  i = 0;
    while((left+i) <= right)
    {
      if(s[left+i] < s[right-i]) {l=true;break;}
      if(s[left+i] > s[right-i]) {r=true;break;}
      ++i;
    }
    if(l) ret[k++] = s[left++];
    else ret[k++] = s[right--];
  }
  return ret;
}
int main()
{
  string s = "ABCCBA";
  cout << minOrder(s) << endl;
  return 0;
}
