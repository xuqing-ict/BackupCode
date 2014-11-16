#include <bits/stdc++.h>
using namespace std;

       int minCut(string s) {
        if(s.empty()) return 0;
        const int n = s.size();
        vector<int> f(n+1,INT_MAX);

        vector<vector<bool> > g(n,vector<bool>(n+1,false));

        /*
        for(int len = 1; len <= n; ++len)
        {
            for(int i = 0 ; i < n;++i)
            {
                g[i][j] = ((s[i] == s[j]) && ( (j-i<2)|| g[i+1][j-1]));
            }
        }*/
        //s[i,...,i+len-1]

        //len == 0
        for(int i = 0 ; i < n ;++i)
            g[i][0] = true;

        for(int i = 0 ; i < n ; ++i)
        {
            //[i,n-1] n-1-i+1 = n-i
            //[i, i+len-1]
            for(int len = 1; len <= (n-i); ++len)
            {
                g[i][len] = (s[i] == s[i+len-1] && (len < 2 || g[i+1][len-2]));
            }
        }

        for(int i = 0 ;  i< n;++i)
        {
            for(int j = 0 ; j < n+1 ; ++j)
                cout << g[i][j] << " ";
            cout << endl;
        }

        //f[0] = -1;
        for(int i = 0;i < n+1; ++i)
        {
            f[i] = i-1;
        }
        //s[i,k]
        for(int i = 0; i < n; ++i)
        {
            for(int k = 0 ; k <= i ; ++k)
            {
                if(g[k][i-k+1] == false) continue;

                f[i+1] = min(f[i+1], f[k] + 1);

               //f[i] = min(f[i],f[k] + isPalin(s.substr(k,i-k)));
            }
        }
        return f[n];
    }
    int main()
    {
        string s = "dde";
        cout <<minCut(s) << endl;

        return 0;
    }
