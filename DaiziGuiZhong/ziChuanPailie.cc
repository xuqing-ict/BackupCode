/**
 * @file ziChuanPailie.cc
 * @brief
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-23
 */

/*给定两个字符串A和B，判断A中是否包含由B中字符重新排列成的新字符串。例如：A=abcdef, B=ba，结果应该返回true。因为ba的排列ab，是A的子串。*/
#include <bits/stdc++.h>
using namespace std;
/*
bool occur(string s, string t)
{
    sort(t.begin(),t.end());
    const int m = s.size();
    const int n = t.size();
    if(m < n) return false;
    string tmp = s.substr(0,n);
    char prev = s[0], cur ;

    sort(tmp.begin(),tmp.end());
    cout << tmp << endl;

    for(int i=1;i+n-1<=m;++i) //注意此处i的范围，i最好理解为是要考察的子字符串的个数
    {
        if(tmp == t) return true;
        cur = s[i+n-1];
        auto pos = find(tmp.begin(),tmp.end(),prev); //利用prev来保存这一步需要删除的元素，因为tmp已经排序，那么tmp的第一个元素就不一定是要删除的元素了。
        *pos = cur;
        prev = s[i];
        sort(tmp.begin(),tmp.end());
        cout << tmp << endl;
    }
    return false;
}
*/
bool occur(string s, string t)
{
    const int m = s.size(), n = t.size();
    if(n > m) return false;
    string tmp;
    sort(t.begin(),t.end());

    for(int i=0;i <= m-n+1; ++i)
    {
        tmp = s.substr(i,n);
        sort(tmp.begin(),tmp.end());
        if(tmp == t) return true;
        auto it = find(tmp.begin(),tmp.end(),s[i]);
        if(i+n >= m ) break;
        *it = s[i+n];
    }
    return false;
}
int main(void)
{
    string s = "ath", t = "the";
    cout << s << endl;
    cout << occur(s,t) << endl;
    return 0;
}
