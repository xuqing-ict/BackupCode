/**
 * @file middleToLast.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-24
 */
//
#include <bits/stdc++.h>
using namespace std;

string convert(const string &s)
{
    cout << s << endl;

    const int n  = s.size();
    if(n == 0) return s;
    stack<char> operand;
    string ret;
    for(int i=0;i<n;++i)
    {
        cout << "cur : " << s[i] << endl;
        char ch = s[i];
        if(isdigit(ch)) 
        {
            ret += ch;
            cout << "1 " << ret << endl;
        }
        else if(ch == '(')
            operand.push('(');
        else if(ch == ')')
        {
            while(!operand.empty() && operand.top() != '(')
            {
                ret += operand.top(); operand.pop();
                cout << "2 " << ret << endl;
            }
            if(operand.empty()) return string("");
            if(operand.top() == '(') operand.pop();
        }
        else
        {
            while(!operand.empty() && operand.top() >= ch)
            {
                ret += operand.top(); operand.pop();
                cout << "3 " << ret << endl;
            }
            operand.push(ch);
        }
    }   
    return ret;

}
int main(void)
{
    const string s = "9+(3-1)*3+10/2";
    cout << convert(s) << endl;
    return 0;
}
