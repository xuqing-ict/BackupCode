/**
 * @file LongestPalindrome.cc
 * @brief
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-26
 */
//最长回文子串

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <algorithm>
using namespace std;


//dp 1
string LongestPalindrome(const string &s)
{
    const int n = s.size();
    if(n < 2) return s;
    bool f[n][n+1];

    fill_n(&f[0][0],n*(n+1),false);
    int start = 0, len = 1;

    f[0][0] = true;
    for(int i=0;i<n;++i)
    {
        f[i][0] = true;
        f[i][1] = true;
    }
    for(int i=n-2;i>=0;--i)
    {
        for(int j=2;j<=n && (i+j-1)<n;++j)
        {
            f[i][j] = f[i+1][j-2] && s[i] == s[i+j-1];
            if(f[i][j] && j > len) {start = i; len = j;}
        }
    }

    return s.substr(start,len);
}

//dp 2
string LongestPalindrome_dp2(const string &s)
{
    const int n = s.size();
    if(n < 2) return s;
    bool f[n][n];

    fill_n(&f[0][0],n*n,false);
    int start=0,len=1;
    f[0][0] = true;

    for(int i=0;i<n;++i)
        f[i][i] = true;

    for(int i = n-1 ; i >= 0; --i)
    {
        for(int j = i+1; j < n;++j)
        {
            if(j == i+1) f[i][j] = (s[i] == s[j]);
            else
                f[i][j] = f[i+1][j-1] && s[i] == s[j];
            if(f[i][j] && (j-i+1) > len) {start = i; len = j-i+1;}
        }
    }

    return s.substr(start,len);
}

//从中间往两端延伸（考虑奇数偶数的情况即可）

string LongestPalindrome_extend(const string &s)
{
    const int n = s.size();
    if(n < 2) return s;
    int low,high;
    int start=0,len=1;
    for(int i=1;i<n;++i)
    {
        //even
        low = i-1;
        high = i;
        while(low>=0&&high<n&&s[low]==s[high])
        {
            if(high-low+1>len)
            {
                start=low;
                len=high-low+1;
            }
            --low;++high;
        }
        //odd
        low = i-1;
        high = i+1;
        while(low>=0&&high<n&&s[low]==s[high])
        {
            if(high-low+1 > len)
            {
                start = low;
                len=high-low+1;
            }
            --low;++high;
        }
    }
    return s.substr(start,len);
}

int valid(const string &lhs, const string &rhs)
{
     //现在需要比较的是两者之中是否只有一个字符串含有# ，排除 12312 输出 12 的情况，保证我找到的两个串的字符是分别出现在#的两边的
    bool label1 = false, label2 = false;
    for(auto a: lhs) if(a == '#') label1 = true;
    for(auto a: rhs) if(a == '#') label2 = true;
    if((label1 && label2 )|| (!label1 &&!label2)) return 0;

    int i = 0;
    for(i=0;i < min(lhs.size(),rhs.size());++i)
        if(lhs[i] != rhs[i]) break;
    return i;
}

//利用后缀数组来解决，将s reverse为s'.然后 求s#s'的最长公共前缀 这个函数依然有问题！！！
string LongestPalindrome_suffix(string s)
{
    const int n = s.size();
    if(n < 2) return s;
    string rs = s;
    reverse(rs.begin(),rs.end());
    s += '#';
    s += rs;

    vector<string> suffix;
    for(int i=0;i < s.size();++i)
        suffix.push_back(s.substr(i));

    sort(suffix.begin(),suffix.end());

    int len=0;
    string ret;
    for(int i=0;i+1<suffix.size();++i)
    {
        int tmp = valid(suffix[i],suffix[i+1]);
        if(tmp > len )
        {
            ret = suffix[i].substr(0,tmp);
            len = tmp;
        }
    }
    return ret;
}
/*
//Manacher O(n)
string Manacher(const string &str)
{
    //add '#'
    string s = "$";
    for(auto a : str)
    {
        s += '#';
        s += a;
    }
    s += '#';
    cout << s << endl;
    const int n = s.size();
    vector<int> P(n,0);
    int right = -1, idx = -1;
    for(int i=1;i<n;++i)
    {
        P[i] = (right > i)? min(P[2*idx-i],right-i):1;
        while(s[i+P[i]] == s[i-P[i]])P[i]++;
        if(i+P[i]>right)
        {
            right = i + P[i];
            idx = i;
        }
    }
    auto pos = max_element(P.begin(),P.end());
    int len = *pos-1;
    string ret;
    int i = pos-P.begin();
    //print
    ret += s[i];
    cout << ret << endl;
    int k=1;
    while(len)
    {
        ret += s[i+k];
        ret = s[i-k]+ret;
        cout << ret << endl;
        ++k;
        --len;
    }
    //trim #
    string ret2;
    for(auto a :ret)
        if(a!='#')ret2 += a;
    return ret2;
}
*/
 string Manacher(const string &s)
{
    cout << "enter..." << endl;
    const int n = s.size();
    string tmp;
    tmp += '$';
    for(auto a : s){tmp += '#'; tmp += a;}
    tmp += '#';
    cout << tmp << endl;
    const int m = tmp.size();
    vector<int> P(m,0);
    int idx = -1, right = -1;
    for(int i=1;i<m;++i)
    {
        P[i] = (i < right)?(min(P[2*idx-i],right-i)):1;
        while(tmp[i+P[i]] == tmp[i-P[i]]) P[i]++;
        if(i + P[i] > right)
        {
            right = i + P[i];
            idx = i;
        }
    }
    auto pos = max_element(P.begin(),P.end());
    int len = *pos-1;
    string ret;
    int i = pos-P.begin();
    ret += tmp[i];
    cout << "middle : " << ret << endl;
    int k = 1;
    //consrtruct the palindrome
    while(len)
    {
        ret += tmp[i+k];
        ret = tmp[i-k] + ret;
        --len;
        ++k;
    }
    //trim '#'
    k = 0;
    for(auto a: ret)
        if(a != '#') ret[k++] = a;
    ret.resize(k);
    return ret;
}

int main(void)
{
    int k = 0;
    srand(time(nullptr));

    while(k < 10)
    {
        ++k;
        int n = rand()%10+20;
        string s;
        /*
        s.resize(n);
        for(int i=0;i<n;++i)
            s[i]=rand()%26+'a';
        cout << s << endl;
        s = "lkkhtqibrzttkjbyfprybjqygbhd";
        */
        cin >> s;
        //string ret1 = LongestPalindrome(s);
        //string ret2 = LongestPalindrome_dp2(s);
        //string ret3 = LongestPalindrome_extend(s);
        //string ret4 = LongestPalindrome_suffix(s);
        string ret4 = Manacher(s);
        //cout << ret1 << endl;
        //cout << ret2 << endl;
        //cout << ret3 << endl;
        cout << ret4 << endl;
        //assert((ret1 == ret2 && ret1 == ret3 ) || ( ret2.size() == ret3.size() && ret1.size() == ret4.size()));
    }
       return 0;

}
