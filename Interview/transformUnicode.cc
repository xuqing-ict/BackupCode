/**
 * @file transformUnicode.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-12
 */
/*#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
*/

#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string,string>::const_iterator iter;

void transform(const string &s, unordered_map<string, string>dict)
{
    if(s.empty() || dict.empty()) return;
    size_t p0=0,p1=0,p2=0;
    while(p0 != string::npos && p0 < s.size())
    {
        p1 = s.find_first_of("#&",p0);
        if(p1 == string::npos)
        {
            cout << s.substr(p0);
            return;
        }
        else
        {
            cout << s.substr(p0,p1-p0);
            p2 = s.find_first_of(";",p1);
            if(p2 == string::npos)
            {
                cout << "Illegal input..." << endl;
                return;
            }
            string from = s.substr(p1,p2-p1);
            if(from.size() > 2&& from[1] == '#')
            {
                int uniNum =atoi(from.substr(2).c_str());
                wcout << wchar_t(uniNum);
            }
            else
            {
                iter it = dict.find(from);
                if(it == dict.end()) 
                {
                    cout<< "Illegal..." << endl;
                    return;
                }
                cout << it->second;
            }
            p0 = p2+1;
        }
    }
    cout << endl;
}   

int main(void)
{
    string s;
    cin >> s;
    unordered_map<string,string> dict;
    dict["&lt"] = "<";
    dict["&gt"] = ">";
    transform(s,dict);
    return 0;
}
