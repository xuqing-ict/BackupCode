/**
 * @file minpalinPartition.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-29
 */

//minimum palindrome partition
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPalinPart(const string &s)
{
    const int n = s.size();
    if(n < 2) return 0;
    vector<vector<bool> > f(n,vector<bool>(n,false));
    for(int i=n-1;i>=0;--i)
    {
        f[i][i] = true;
        for(int j=i+1;j<n;++j)
        {
            if(i+1 == j) f[i][j] = (s[i] == s[j]);
            else f[i][j] = (f[i+1][j-1] && s[i] == s[j]);
        }
    }

    vector<int> g(n+1,0);
    g[0] = -1;
    //previous i chars
    for(int i=2;i<n+1;++i)
    {
        g[i] = i-1;
        for(int j=0;j<i;++j) // j is also length
            if(f[j][i-1]) g[i] = min(g[i],g[j]+1);
    }
    return g[n];
}

int main(void)
{
    string s;
    cin >> s;
    cout << minPalinPart(s) << endl;
    return 0;
}


