/**
 * @file translateDigit.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
 */
//翻译数字
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>


using namespace std;

char dict[27];

ostream_iterator<char> out(cout,"\t");

bool translated(const string &s)
{
    const int n  = s.size();
    if(n == 0 ) return true;
    vector<bool> f(n+1,false);
    f[0] = true;
    f[1] = (s[0] != '0');
    for(int i=2;i<=n;++i) // length
    {
        int tmp = atoi(s.substr(i-2,2).c_str());
        f[i] = (f[i-1] && s[i-1] != '0') || (f[i-2] && (tmp >=10 && tmp <= 26));
    }
    return f[n];
}
//dfs to print all result
void helper( const string &s, int cur_index, const int max_index, string cur, vector<string> &ret)
{
    if(cur_index > max_index) {ret.push_back(cur); return ;}
    //one digit
    if(s[cur_index] == '0') return; //illegal
    cur += dict[s[cur_index]-'0'];
    helper(s,cur_index+1,max_index,cur,ret);
    cur.pop_back();
    //two digit
    int tmp=atoi(s.substr(cur_index,2).c_str());
    if(tmp >= 10 && tmp <= 26)
    {
        cur += dict[tmp];
        helper(s,cur_index+2,max_index,cur,ret);
    }
}   
vector<string> helper(const string &s) 
{
    const int  n = s.size();
    if(n == 0 ) return vector<string>();
    vector<string> ret;
    string cur;
    helper(s,0,n-1,cur,ret);
    return ret;
}

void print(const string &s , int cur_index, string &cur, vector<string> &ret, const vector<vector<int> > parent)
{
    if(cur_index == 0) {reverse(cur.begin(),cur.end());ret.push_back(cur);return;}
    string tmp = cur;
    for(auto idx : parent[cur_index])
    {
        cur = tmp;
        //cur = s.substr(idx,cur_index-idx) + cur;
        int t = atoi(s.substr(idx,cur_index-idx).c_str());
        cur += dict[t];
        print(s,idx,cur,ret,parent);
    }
}


//record the parent to print all result
vector<string> printAll(const string &s)
{
    const int n = s.size();
    if(n == 0) return vector<string>();
    vector<vector<int> > f(n+1,vector<int>()); //record the parent of each solution
    //f[i] :  the last index of s[i-1]
    vector<bool> g(n+1,false);
    g[0] = true;
    g[1] = (s[0] != '0');
    f[1].push_back(0);
    for(int i=2;i<=n;++i)
    {
        //one digit
        if(g[i-1] && s[i-1] != '0')
        {
            g[i] = true;
            f[i].push_back(i-1);
        }
        
        //two digit
        int tmp = atoi(s.substr(i-2,2).c_str());
        if( g[i-2] && (tmp >= 10 && tmp <= 26))
        {
            g[i] = true;
            f[i].push_back(i-2);
        }
    }
    for(int i=0;i<f.size();++i)
    {
        for(auto a: f[i])
            cout << a << " ";
        cout << endl;
    }
    vector<string> ret;
    string cur;
    print(s,n,cur,ret,f);
    return ret;
}
int main(void)
{
    string s;
    cin >> s;
    dict[0] = '#' ; //illegal char
    for(int i=0;i<26;++i)
        dict[i+1] = 'a'+i;
    /*
    cout << "dict : ";
    copy(dict,dict+27,out);
    cout << endl;
    */
    bool label = translated(s);
    cout << "ret : " << boolalpha << label << endl;
    cout << "ans : ";vector<string> ret = helper(s);
    for(auto a: ret) cout << a << " ";cout << endl;
    ret = printAll(s);
    for(auto a:ret)
        cout << a << endl;
    return 0;
}
