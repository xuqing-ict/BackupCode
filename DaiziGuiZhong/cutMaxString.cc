/**
 * @file cutMaxString.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-31
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;

int cutMaxString(const string &s, const int m)
{
    const int n = s.size();
    if(n < m) return -1; // illegal input
    vector<vector<int> > f(n+1,vector<int>(m+1,0));
    // f[len][# of cuts]

    //j = 1 : 1 segment
    for(int i=1;i<=n;++i)
        f[i][1] = atoi(s.substr(0,i).c_str());

    for(int i=1;i<=n;++i) //[0...i-1]
    {
        for(int j=2;j<=m;++j) //j segments
        {
            for(int k=j-1;k<=i;++k) // the last cut
                f[i][j] = max(f[i][j],atoi(s.substr(k,i-k).c_str())*f[k][j-1]);
        }
    }
    return f[n][m];
}

int main(void)
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << "ans : " << cutMaxString(s,k) << endl;
    return 0 ;
}
