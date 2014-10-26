/**
 * @file palinPatition.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-09
 */
/*对一个字符串按照回文进行分割，例如aba|b|bbabb|a|b|aba就是字符串ababbbabbababa的一个回文分割，每一个字串都是一个回文。请找到可以分割的最少的字串数。例如：
 *
 * ababbbabbababa最少4个字符串，分割三次：a|babbbab|b|ababa
 * 如果字符串整体是回文，则需要0次分割，最少1个字符串*/
#include <bits/stdc++.h>
using namespace std;

int palinPatition(const string &s)
{
    const int n = s.size();
    if (n < 2) return 1;
    bool g[n][n];
    fill_n(&g[0][0],n*n,false);
    //init
    for(int i=0;i<n;++i) g[i][i] = true;
    
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i+1;j<n;++j)
        {
            if (i+1 == j) 
            {
                g[i][j] = (s[i] == s[j]); 
                continue;
            }
            g[i][j] = (g[i+1][j-1] && s[i]==s[j]);
        }
    }
    int f[n+1];
    fill_n(&f[0],n+1,INT_MAX);
    f[0] = 0;
    for(int i=1;i<=n;++i) //previous i chars
    {
        f[i] = i; //worst case
        for(int k=0;k<=i;++k) //previous k chars
        {
            if(g[k][i-1]) f[i] = min(f[i],f[k]+1);
        }
    }
    return f[n];
}

int main(void)
{
    string s;
    cin >> s;
    cout << palinPatition(s) << endl;
    return 0;
}
