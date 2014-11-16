
#include <bits/stdc++.h>
using namespace std;

int longestCommonStr(const string &s,const string &t)
{
    if(s.empty() || t.empty()) return 0;
    const int m = s.size(), n = t.size();
    int ret=0;

    vector<int> f(n+1,0);
    for(int i=1;i<=m;++i)
    {
        for(int j=n;j>=1;--j)
        {
            if(s[i-1] == t[j-1]) f[j] = f[j-1]+1;
            else f[j] = 0;
            if(f[j] > ret) ret=f[j];
        }
    }
    return ret;
}

int main(void)
{
    string text = "acaccbabb";
    string query = "acbac";
    cout << longestCommonStr(text,query) << endl;
    return 0;
}
