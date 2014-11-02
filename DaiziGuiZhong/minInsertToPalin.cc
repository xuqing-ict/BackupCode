/**
 * @file Candy.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;


int minInsert(const string &s)
{
    const int n = s.size();
    if(n < 2) return 0;
    vector<int> prev(n,0), next(n,0);
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i+1;j<n;++j)
        {
            next[j] = min(prev[j],next[j-1]) + 1;
            if(s[i] == s[j]) { next[j] = min(next[j],prev[j-1]);}

        }
        prev.swap(next);
    }
    return prev[n-1];
}

int main(void)
{
    
    int n;
    string s;

    while(scanf("%d",&n) != EOF)
    {
        cin >> s;
        cout << minInsert(s) << endl;
    }
    return 0 ;
}
