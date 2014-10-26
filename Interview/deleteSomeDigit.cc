/**
 * @file deleteSomeDigit.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-24
 */
/*n位的一个数，去掉 k 位，使得剩余的数最小。*/
//stack

#include <bits/stdc++.h>
using namespace std;

string deleteKDigit(const string s, const int k)
{
    if(k <= 0) return s;
    string ret;
    stack<char> mys;
    const int n = s.size();
    int tmp = k;
    if(k > n) return s;
    for(int i=0;i<n;++i)
    {
        char cur = s[i];
        while(!mys.empty() && mys.top() > cur && tmp > 0)
        {
            mys.pop();
            --tmp;
        }
        mys.push(cur);
    }
    while(tmp > 0) {mys.pop();--tmp;}
    while(!mys.empty())
    {
        ret.push_back(mys.top()); mys.pop();
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
/* //run error
string deleteKDigit2(const string s, const int k)
{
    if(k <= 0) return s;
    
    const int n = s.size();
    string ret;
    ret.resize(n-k);
    int tmp = k;
    int len = 0;
    for(int i=0;i<n;++i)
    {
        char cur = s[i];
        while(len > 0 && ret[len-1] > cur && tmp > 0)
        {
            --len;
            --tmp;
        }
        ret[len == 0 ? 0 : len-1] = cur;
        len++;
    }
    return ret;
}

*/

int main(void)
{
    string s = "1341215";
    const int k = 3;
    string ret1 = deleteKDigit(s,k);
    cout <<  s << endl;
    cout << ret1 << endl;
    return 0;
}
