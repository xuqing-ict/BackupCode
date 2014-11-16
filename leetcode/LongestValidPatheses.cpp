//Longest Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

int LVP(const string &s)
{
    if(s.empty()) return 0;
    int  i = 0;
    stack<int> lefts;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i] == ')')
        {
            if(!lefts.empty())
            {
                count +=2;
            }
        }
    }
}
int main()
{
    string s = "())";
    cout << LVP (s) << endl;

    return 0;
}
