/**
 * @file bracketMatch.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-09
 */
/*给定字符串，输出括号是否匹配，例如，
 *
 * "()" yes；
 * ")(" no；
 * "(abcd(e)" no；
 * "(a)(b)" yes。
 *
 * 要求必须用递归写，整个实现不可以出现一个循环语句。*/
#include <bits/stdc++.h>
using namespace std;

bool helper(const string &s, int cur_index, const int max_index, int &left)
{
    if(left < 0 || cur_index > max_index)
    {
        if(left == 0) return true;
        return  false;
    }
    if(s[cur_index] == '(') left += 1;
    else if(s[cur_index] == ')') left -=1;
    return helper(s,cur_index+1,max_index,left);
}
bool valid(const string &s)
{
    const int n = s.size();
    if(n == 0 ) return true;
    
    int left=0;
    return helper(s,0,n-1,left);
}

int main(void)
{
    string s;
    cin >> s;
    cout << valid(s) << endl;
    return 0;
}
