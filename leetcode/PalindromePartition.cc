/**
 * @file PalindromePartition.cc
 * @brief palindrome partition
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-11
 */
/*Given a string s, partition s such that every substring of the partition is a palindrome.

  Return all possible palindrome partitioning of s.

  For example, given s = "aab",
  Return

  [
  ["aa","b"],
  ["a","a","b"]
  ]
  */
//dfs version
#include <bits/stdc++.h>
using namespace std;
/*
bool isPalin(const string &s)
{
    const int n=s.size();
    if(n<2) return true;
    int i=0,j=n-1;
    while(i<j && s[i]==s[j]){++i;--j;}
    return i>=j;
}

void helper(const string s, vector<string> &cur, int index, const vector<vector<int> > &prev, vector<vector<string> > &ret)
{
    if(index==0 || prev[index].empty()) 
    {
        if(index==0)
        {j
            ret.push_back(cur);
            reverse(ret.back().begin(), ret.back().end());
        }
        return;
    }
    for(int i=0;i<prev[index].size();++i)
    {
        cur.push_back(s.substr(prev[index][i],index-prev[index][i]));
        helper(s,cur,prev[index][i],prev,ret);
        cur.pop_back();
    }
}

vector<vector<string>> partition(const string s)
{
    vector<vector<string> > ret;
    if(s.empty()) return ret;
    const int n=s.size();
    vector<int> f(n+1,false);
    vector<vector<int> > prev(n+1,vector<int>());

    f[0]=true;
    for(int i=1;i<=n;++i) //[0--i-1]
    {
        for(int k=0; k<i;++k) //index
        {
            string tmp=s.substr(k,i-k);
            if(isPalin(tmp) && f[k]) 
            {
                f[i]=true;
                prev[i].push_back(k);
            }
        }
    }

    cout << "prev : " << endl;
    for(int i=0;i<=n;++i)
    {
        cout << i << " \t " ;
        for(int j=0;j <prev[i].size();++j)
            cout << prev[i][j] << "\t";
        cout << endl;
    }
    cout << "return "<< endl;

    vector<string> cur;
    helper(s,cur,n,prev,ret);
    return ret;
}

int minCut(const string s) 
{

    const int n=s.size();
    if(n<2) return 0;
    vector<int> f(n+1,INT_MAX);
    vector<bool> g(n+1,false);
    g[0]=true;
    f[0]=-1;

    for(int i=1; i<=n; ++i)
    {
        for(int k=0; k<i; ++k)
        {
            if(g[k] && isPalin(s.substr(k,i-k)))
            {
                g[i]=true;
                f[i]=min(f[i],f[k]+1);
            }
        }
    }
    cout << "minCut: ";
    for(int i=0;i<=n;++i)
        cout << f[i] << "\t" ;
    cout << endl;
    return f[n];
}
int minCut2(string s){
    vector<vector<int> > ok;

    int len = s.length();
    ok.resize(len);
    for(int i=0; i<len; i++)
        ok[i].resize(len);
    for(int i=1; i<=len; i++)
        for(int j=0; j<len-i+1; j++){
            int st = j, en = j+i-1;
            if (s[st] == s[en] && (st+1 > en-1 || ok[st+1][en-1]) ){
                ok[st][en] = 1;
            }else{
                ok[st][en] = 0;
            }
            //		cout << st << " " << en << " " << ok[st][en] << endl;
        }
    vector<int> dp(len, len);
    dp[0] = 0;
    for(int i=0; i<len; i++){
        if (i != 0){
            dp[i] = dp[i-1]+1;
        }
        for(int j=i-1; j>=0; j--)
            if (s[i] == s[j] && (j+1 > i-1 || ok[j+1][i-1]) ){
                dp[i] = min(dp[i], (j==0 ? 0 : dp[j-1]+1) );
            }
        //		cout << i << " " << dp[i] << endl;
    }
    return dp[len-1];
}

ostream_iterator<string> out(cout, "\t");

int main(void)
{
    string s="abba";
    vector<vector<string> > ret=partition(s);
    for(int i=0;i<ret.size();++i)
    {
        copy(ret[i].begin(), ret[i].end(),out);
        cout << endl;
    }
    cout << "minCut..." << endl;
    cout << minCut(s)<< endl;
    cout << isPalin("aabb") << endl;
    return 0;
}
*/

ostream_iterator<string> out(cout, "\t");
void helper(const string &s, int cur_index, const int max_index, vector<string> &cur, vector<vector<string> > &ret,const vector<vector<bool> > &valid)
{
    if(cur_index > max_index)
    {
        ret.push_back(cur);
        return;
    }
    for(int i=cur_index;i<=max_index;++i)
    {
        if(valid[cur_index][i]) 
        {
            cur.push_back(s.substr(cur_index,i-cur_index+1));
            helper(s,i+1,max_index,cur,ret,valid);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    const int n = s.size();
    vector<vector<string> > ret;
    if(n == 0) return ret;

    vector<vector<bool> > valid(n,vector<bool>(n,false));
    for(int i=0;i<n;++i) valid[i][i] = true;
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(i+1 == j) 
            {
                valid[i][j] = (s[i] == s[j]); 
                continue;
            }
            valid[i][j] = (valid[i+1][j-1] && s[i] == s[j]);
        }
    }

    vector<string> cur;
    helper(s,0,n-1,cur,ret,valid);
    return ret;
}
int main(void)
{
    string s;
    cin >> s;
    vector<vector<string> > ret = partition(s);
    cout << ret.size() << endl;
    for(int i=0;i<ret.size();++i)
    {
        copy(ret[i].begin(), ret[i].end(),out);
        cout << endl;
    }
    return 0;
}
