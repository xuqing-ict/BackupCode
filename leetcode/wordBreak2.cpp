// Last Update:2014-08-08 22:22:02
/**
 * @file wordBreak2.cpp
 * @brief word break II
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-08
 */

#include <bits/stdc++.h>
using namespace std;

void print(const string &s, int cur_index, const vector<vector<int> > &prev, string &path, vector<string> &ret)
{
    if(cur_index == 0) 
    {
        ret.push_back(path);
        return;
    }
    if(prev[cur_index].size())
    {
        for(int j=0; j<prev[cur_index].size();++j)
        {
            string temp=path;

            if(!path.empty()) path = ' ' + path;
            path = s.substr(prev[cur_index][j], cur_index-prev[cur_index][j]) + path;
            print(s,prev[cur_index][j],prev,path,ret);

            path=temp;
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    const int n = s.size();
    vector<string> ret;
    if( n == 0 ) return ret;
    vector<vector<int> > prev(n+1, vector<int>());
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for(int i=1; i<=n; ++i)
    {
        for(int j=0;j<i;++j)
        {
            if(dp[j] && dict.find(s.substr(j,(i-j))) != dict.end())
            {
                prev[i].push_back(j);
                dp[i]=true;
            }
        }
    }
    string path;
    print(s,n,prev,path,ret);
    return ret;
}

int main(void)
{
    string s = "a";
    unordered_set<string> dict;
    dict.insert("a");
    vector<string> ret = wordBreak(s,dict);
    cout << ret.size() << endl;
    for(auto a: ret)
        cout << a << endl;
    cout << endl;
    return 0;
}
