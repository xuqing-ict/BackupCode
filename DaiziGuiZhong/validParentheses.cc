/**
 * @file validParentheses.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-29
 */

//valid parenthese
#include <iostream>
#include <climits>
#include <algorithm>

#include <stack>
using namespace std;

bool valid(const string &s)
{
    if(s.empty()) return true;
    const int n = s.size();
    if(n < 2) return false;
    stack<char> left;
    for(auto a : s)
    {
        if(a != '(' && a != ')') continue;
        if(a == '(') left.push(a);
        else 
        {
            if(left.empty()) return false;
            left.pop();
        }
    }
    return left.empty();
}
bool helper(const string &s, const int  idx, const int max_index, int &left)
{
    if(s[idx] != '(' && s[idx] != ')')  return helper(s,idx+1,max_index,left);
    if(idx > max_index) return left == 0;
    if(s[idx] == '(')
    {
        ++left;
    }
    else
    {
        if(left == 0) return false;
        --left;
    }
    return helper(s,idx+1,max_index,left);
}

bool valid_2(const string &s)
{
    const int n = s.size();
    int left = 0;
    bool ret = helper(s,0,n-1,left);
    return ret;
}
int main(void)
{
  string s = "(feywgfue) (dbjafh)(fry(erfge)Bfrg))";
    cout << valid(s) << endl;
    cout << valid_2(s) << endl;
    return 0;
}
