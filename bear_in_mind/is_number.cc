/**
 * @file is_number.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-09
 */
//verify is number or not
#include <bits/stdc++.h>
using namespace std;

bool is_number(const string &str)
{
    if(str.empty()) return false;
    bool dot=false,negate=false;
    int i=0;
    if(str[i] == '+' || str[i] == '-')
    {
        negate=true;++i;
    }
    for(;i<str.size();++i)
    {
        if(!isdigit(str[i]) && str[i] != '.') return false;
        if(str[i] == '.')
        {
            if(dot) return false;
            dot=true;
        }
    }
    return true;
}
int main(void)
{
    string s;
    cin >> s;
    cout << is_number(s) << endl;
    return 0;
}
