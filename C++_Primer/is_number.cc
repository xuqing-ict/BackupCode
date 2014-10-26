/**
 * @file is_number.cc
 * @brief is_number
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-17
 */

#include <bits/stdc++.h>
using namespace std;

inline bool is_number(const string &str)
{
    if(str.empty()) return false;
    bool dot = false;

    for(int i=0; i<str.size(); ++i)
    {
        if(!isdigit(str[i]) && str[i] != '.') return false;
        if(str[i] == '.')
        {
            if(dot) return false;
            dot = true;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    if(is_number(s))
        cout << "is number..." << endl;
    else 
        cout << "Illegal number..." << endl;
    return 0;
}
