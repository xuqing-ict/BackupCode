/**
 * @file Test.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-18
 */

//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int value[100001];
int cost[501];
int all=0;
int f[100001][501];

int maxValue(const int n)
{
    for(int j=1;j<=n;++j) //select or not select
    {
        for(int i = 0; i<= all;++i)
        {
            if(i >= cost[j])
                f[i][j] = max(f[i-cost[j]][j-1] + value[j], f[i][j-1]);
            else
                f[i][j] = f[i][j-1];
        }
    }
    return f[all][n];
}

int main(void)
{
    int n;
    while(scanf("%d %d",&n,&all) != EOF)
    {
        for(int i=1;i<=n;++i)
        {
            cin >> cost[i];   
            cin >> value[i];
        }
        cout << maxValue(n) << endl;
    }
    return 0;
}
