/**
  * @file wideStringMatch.cc
  * @brief wide char match
  * @author Qing Xu, xuqinguestc@163.com
  * @version 0.1.00
  * @date 2014-06-29
  */
#include <bits/stdc++.h>
using namespace std;

bool isMatch(const char *s, const char *p) {
  if(p == '\0') return s == '\0';

  if(*p == '*')
  {
    while(*s != '\0' && (*(p+1) == *s || *(p+1) == '?'))
    {
      if(isMatch(s+1,p+2)) return true;
      ++s;
    }
    return isMatch(s,p+1);
  }
  else
  {
    if(*s != '\0' && (*p == *s || *p == '?'))
      return isMatch(s+1,p+1);
  }
//  return false;
}


int main()
{
  const char *s ="aa";
  const char *p = "a*";
  if(isMatch(s,p)) cout << "match..." << endl;
  else cout << "fail..." << endl;
  return 0;
}

