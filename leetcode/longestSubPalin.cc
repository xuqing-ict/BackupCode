/**
 * @file longestSubPalin.cc
 * @brief longest sub palindrome string
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-15
 */

//manacher 
#include <bits/stdc++.h>
using namespace std;

string longestPalin( const string s)
{
  int  n = s.size();
  if(n < 2) return s;
  //add special label
  string str = "$#";
  for(int i = 0 ;  i< n ;++i)
  {
    str += s[i];
    str += '#';
  }
  cout << s << endl;
  cout << str << endl;
  n = str.size();
  vector<int> p (n,0); 
  int right = 0, center = 0;

  for(int i=0; i<n ; ++i)
  {
   /* if(str[i] == '#' || str[i] == '$')
    {
      p[i] = 0; 
      continue;
    }
    */
    if(right > i)
    {
      p[i] = min(p[2*center-i], right-i);
    }
    else
    {
      p[i] = 1;
    }
    //extend p[i] if possible 
    while(str[i-p[i]] == str[i+p[i]])p[i]++;
    cout << i << "xq" << endl;

    if(i+p[i] > right)
    {
      right = i + p[i]; 
      center = i;
    }
  }
  cout << "end..." << endl;
  int index = 0;
  string ret_str;
  for(int i=0; i<n ; ++i)
  {
    cout <<  p[i] << " "; 
    if(p[index] < p[i]) 
    {
      index = i;
      //ret_str = s.substr(i-p[i]/2,p[i]-1) ;
      //cout << ret << " " << ret_str << endl;
    }
  }
  cout << endl;
  cout << "index : " << index << endl;

  for(int i = index - p[index] + 1; i <= index+p[index]-1;++i)
    if(str[i] != '#' && str[i] != '$')
      ret_str += str[i];
  return ret_str;
}
int main()
{
  string s;// = "aba";
  cin >> s;
  cout << longestPalin(s) << endl;
  return 0;
}
