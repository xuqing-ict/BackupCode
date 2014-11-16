#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>

using namespace std;


void helper(const string &s, int curPos, const int &maxPos, int &ret)
{
    if( curPos == maxPos )//|| s.substr(curPos,1) == "0" || ( maxPos - curPos > 1 && atoi((s.substr(curPos,2)).c_str()) > 26 ))
    {
        if(curPos == maxPos && maxPos != 0 )
            ret += 1;
        return;
    }
    for(int i = 1 ; i <= min(2,maxPos-curPos); ++i)
    {
        string sub = s.substr(curPos,i);
        if(atoi(sub.c_str()) > 26 || sub[0] == '0')
            continue;
        helper(s,curPos+i,maxPos,ret);
    }
}
    int numDecodings(string s) {
        int ret = 0 ;
        int maxPos = s.size();
        helper(s,0,maxPos,ret);
        return ret;
    }

    int numDecodings2(string s) {
        int n = s.size();
        vector<int> f(n+1,0);
        if(n == 0 ) return 0;
        f[0] = 1;
        f[1] = (s[0] != '0');
        if(f[1] == 0) return 0;
        for(int i = 2 ; i <= n ; ++i)
        {
            if(s[i-1] !=  '0')
                f[i] += f[i-1];
            if(s[i-2] != '0')
            {
                int sub = atoi(s.substr(i-2,2).c_str());
                if(sub >= 1 && sub <= 26)
                    f[i] += f[i-2];
            }
            //f[i] = (f[i-1] * (s[i-1] != '0')) +  (f[i-2] * ( s[i-2] != '0' && atoi(s.substr(i-2,2).c_str())) <= 26 && atoi(s.substr(i-2,2).c_str()) >= 1);
        }
        copy(f.begin(), f.end(), ostream_iterator<int>(cout,"\t"));
        cout << endl;
        return f[n];
    }
    int main()
    {
        string s = "100";
        cout << numDecodings2(s) << endl;
        return 0;

    }
