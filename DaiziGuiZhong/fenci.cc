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

using namespace std;

bool dictPartition(const string &s,const unordered_set<string> &dict)
{
    const int n = s.size();
    if(n == 0) return false;
    vector<bool> f(n+1,false);
    f[0]=true;
    for(int i=1; i<=n;++i) //len
    {
        for(int j=0;j<i;++j)
        {
            auto it = dict.find(s.substr(j,i-j));
            if(f[j] && it != dict.end()) {f[i]=true;break;}
        }
    }
    return f[n];
}
int main(void)
{
    string s;
    cin >> s;
    unordered_set<string> dict;
    dict.insert("hello");
    dict.insert("world");
    cout << boolalpha << dictPartition(s,dict) << endl;
    return 0 ;
}
