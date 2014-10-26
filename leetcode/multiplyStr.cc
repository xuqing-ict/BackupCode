/**
 * @file multiplyStr.cc
 * @brief multiply string
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */

#include <bits/stdc++.h>
using namespace std;

void addSameLenString(string s1, string s2, int cur_index, int &carry, string &ret);
string addString(string s1, string s2)
{
  if(s1.empty())return s2;
  if(s2.empty()) return s1;

  int n1 = s1.size(), n2 = s2.size();
  if (n1 < n2) swap(s1,s2);
  for(int i = 0 ; i < abs(n1-n2);++i)
    s2  = '0' + s2;

  int carry = 0;
  string ret(max(n1,n2),'0');
  addSameLenString(s1,s2,0,carry,ret);
  if(carry) ret = '1' + ret;
  return ret;
}
void addSameLenString(string s1, string s2, int cur_index, int &carry, string &ret)
{
  if(cur_index >= s1.size()) return;
  addSameLenString(s1,s2,cur_index+1,carry,ret);
  int sum = (s1[cur_index] - '0') + (s2[cur_index] - '0') + carry;
  carry = sum/10;
  ret[cur_index] = ( sum%10 + '0');
}
string ComputeStrChar(string s1_t,char c)
{
  int index = c - '0';

  string ret;
  for(int i = 0 ;i < index; ++i)
  {
    ret = addString(ret,s1_t);
  }
  return ret;
}

string multiply(string num1, string num2) {
  int n1 = num1.size(), n2 = num2.size();
  if(n1 == 0 || n2 == 0)
  {
    cerr << "Input paramter illegal!!!" << endl;
    exit(1);
  }

  bool label = false;
  //+ /-
  int i=0,j=0;
  if(num1[0] == '-' || num2[0] == '-')
  {
    if(num1[0] == '-') {label = !label; ++i;}
    if(num2[0] == '-') {label = !label; ++j;}
  }
  string s1_t = num1.substr(i);
  string s2_t = num2.substr(j);
  if(s1_t.size() < s2_t.size())
    swap(s1_t, s2_t);

  int k = 0;
  int index = 0;
  for( k = 0 ; k < s1_t.size(); ++k)
  {
    if (s1_t[k] == '.')
    {
      break;
    }
  }
  if ( k < s1_t.size() )
  {
    index += (s1_t.size()-k-1);
    s1_t.erase(s1_t.begin()+k);
  }
  for( k = 0 ; k < s2_t.size(); ++k)
  {
    if (s2_t[k] == '.')
    {
      break;
    }
  }
  if ( k < s2_t.size() )
  {
    index += (s2_t.size()-k-1);
    s2_t.erase(s2_t.begin()+k);
  }

  string ret;
  for(int k = s2_t.size()-1; k >=0 ; --k)
  {
    string temp = ComputeStrChar(s1_t,s2_t[k]);
    temp += string(s2_t.size()-1-k,'0');
    ret = addString(ret,temp);
  }

  if(index)
  {
    if(index < ret.size())
    {
      ret.insert(ret.begin() + (ret.size()-index),'.');
    }
    else
    {
      int size = index - ret.size() + 1;
      string insert_s = "0.";
      insert_s += string(size,'0') ;
      ret = insert_s + ret;
    }
  }
  if(label) ret = '-' + ret;
  return ret;
}
string multiply2(string num1, string num2) {
  int l1 = num1.size(), l2 = num2.size();
  if (l1 == 0 || l2 == 0) return "0";
  if (num1.compare("0") == 0 || num2.compare("0") == 0){
    return "0";
  }
  string a;
  for (int i = 0; i<=l1+l2+1; i++){
    a = a + "0";
  }
  int la = l1 + l2+1;
  for (int i = 0; i<l1; i++){
    int t = 0;
    int mult = num1[l1-i-1]-'0';
    for (int j = 0; j<l2 || t; j++){
      assert(la-i-j-1>=0);
      int x = mult * (j<l2?num2[l2-j-1]-'0':0) + a[la-i-j-1]-'0' + t;
      a[la-i-j-1] = x%10+'0';
      t = x/10;
    }
  }
  if (a[0] == '0') a = a.substr(1);
  return a;
}

int main()
{
  cout << multiply2("234","456") << endl;
  return 0;
}
