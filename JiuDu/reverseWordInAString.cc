//reverse word in a string

#include <bits/stdc++.h>
using namespace std;

void ReverseWord(string &s)
{
    if(s.empty()) return;
    const int n = s.size();
    int i=0;
    string /*word,*/ ret;
    while(i < n)
    {
        while(i < n && s[i] == ' ')++i;
        //word.clear();
        int prev=i;
        while(i < n && s[i] != ' ')
        {
            //word += s[i];
            ++i;
        }
        string word = s.substr(prev,i-prev);
        if(!word.empty())
        {
            reverse(word.begin(), word.end());
            ret += word;
            ret += ' ';
        }
    }
    if(!ret.empty()) ret.pop_back();
    cout << ret << endl;
    reverse(ret.begin(), ret.end());
    cout << ret << endl;
    s=ret;
}

int main(void)
{
    string s = "  a  b";
    cout << s << endl;
    ReverseWord(s);
    cout << s << endl;
    return 0;
}
