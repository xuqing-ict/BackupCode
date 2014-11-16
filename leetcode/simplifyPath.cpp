   #include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <stack>

#include <assert.h>

using namespace std;
    string simplifyPath(string path) {
        int n = path.size();
        if(n == 0) return string("/");
        int  i = 0 ;
        stack<string> s;
        s.push("/");
        if(path[0] != '/')return "";
        ++i;
        int start ;
        string prev("..");
        string cur(".");

        while (i < n)
        {
            start = i;
            while(i < n && path[i] != '/') ++i;
            string sub = path.substr(start, i - start);
            cout << "sub : " << sub << endl;
            if(!sub.empty())
            {
                cout << "sub is not empty..." << endl;
                assert(sub == prev);
                if( sub == prev )
                {
                    cout << "sub == .." << endl;
                    if( s.top() != "/")
                        s.pop();
                }
                else if (sub == cur)
                {
                    cout << "sub == ." << endl;
                    i = i;
                }
                else
                {
                    cout << "sub else" << endl;
                    s.push(sub);
                }
            }
            ++i;
        }
        string ret;
        while(!s.empty())
        {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
    int main()
    {
        string s = "/..";
        cout <<  simplifyPath(s) << endl;
        return 0;

    }
