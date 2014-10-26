/**
 * @file JiDan.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-02
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 100;

int JiDan(const int level, const int n)
{
    if(n <= 0 || level <= 0 ) return -1;
    int f[level+1][n+1];
    fill_n(&f[0][0],(level+1)*(n+1),INT_MAX);

    //only one egg
    for(int i=0;i<=level;++i)f[i][1] = i-1;
    for(int i=0;i<=level;++i)
    {
        for(int j=0;j<=n;++j)
            cout << f[i][j] << "\t";
        cout << endl;
    }
    
    for(int i=1;i<=level;++i)
    {
        for(int j=n;j>1;--j)
        {
            f[i][j] = min(f[i][j], 1 + max(f[i-1][j-1], f[level-i][j]));
        }
    }
    for(int i=0;i<=level;++i)
    {
        for(int j=0;j<=n;++j)
            cout << f[i][j] << "\t";
        cout << endl;
    }
    return f[level][n];
}

int main(void)
{
    cout<< "result : " << JiDan(2,2) << endl;
    return 0;
}

