/**
 * @file maximumCountTInS.cc
 * @brief count the occurance number of string T in S
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-16
 */

#include <bits/stdc++.h>
using namespace std;

int CountTInS(const string &s, const string &t)
{
  const int n1 = s.size(), n2 = t.size();
  if (n1 < n2)
  {
    return 0;
  }
  int f[n1+1][n2+1];
  fill(&f[0][0], &f[0][0] + (n1+1)*(n2+1), 0);
  //i -- n1, j -- n2
  for(int i = 0 ; i < n1+1 ; ++i)
  {
    f[i][0] = 1;
  }
  for(int i = 1 ; i < n1+1 ; ++i)
  {
    for(int j = 1; j < n2+1; ++j)
    {
      //f[i][j] = max(f[i-1][j-1] * (s[i-1] == t[j-1]?1:0) + f[i-1][j], f[i-1][j]);
      f[i][j] = f[i-1][j-1] * (s[i-1] == t[j-1]?1:0) + f[i-1][j];
    }
  }
  return f[n1][n2];
}
int main()
{
  string s, t;
  cout << "s : ";
  cin >> s;
  cout << "t : ";
  cin >> t ;
  cout << CountTInS(s,t) << endl;
  return 0;
}
