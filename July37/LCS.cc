
#include <bits/stdc++.h>
using namespace std;
void printPath(const string s1, const string s2, const vector<vector<int> > &f,int n1, int n2, string &ret);

int LCS(const string s1, const string s2)
{
    //DP
    const int n1=s1.size(),n2=s2.size();
    vector<vector<int> > f(n1+1,vector<int>(n2+1,0));
    //O(m*n)
    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            f[i][j] =  max( f[i-1][j-1]+((s1[i-1]==s2[j-1])?1:0), max( f[i-1][j],f[i][j-1]));
        }
    }
    for(int i=0;i<=n1;++i)
    {
        for(int j=0;j<=n2;++j)
            cout << f[i][j] << "\t";
        cout << endl;
    }
    string ret;
    printPath(s1,s2,f,n1,n2,ret);
    cout << "result : " << ret << endl;
    return f[n1][n2];
}
void printPath(const string s1, const string s2, const vector<vector<int> > &f,int n1, int n2, string &ret)
{
    if(f[n1][n2] == 0) return;
    if(f[n1][n2] == f[n1-1][n2-1]+1)
    {
        printPath(s1,s2,f,n1-1,n2-1,ret);
        ret.push_back(s1[n1-1]);
    }
    else if(f[n1][n2] == f[n1-1][n2]) printPath(s1,s2,f,n1-1,n2,ret);
    else printPath(s1,s2,f,n1,n2-1,ret);
}
int main(void)
{
    const string s1 = "ABCBDAB", s2="BDCABA";
    cout << LCS(s1,s2) << endl;
    return 0;
}
