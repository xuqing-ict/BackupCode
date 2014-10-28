/**
 * @file longest01.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-28
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;
typedef pair<int,int> P;

string longest012(const string &s)
{
    const int n = s.size();
    string ret;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int c1=0,c0=0;
            for(int k=i;k<=j;++k)
            {
                if(s[k] == '0')c0+=1;
                else c1+=1;
            }
            if(c1 == c0 && (j-i+1) > ret.size()) ret=s.substr(i,j-i+1);
        }
    }
    return ret;
}
string longest01(const string &s)
{
    const int n = s.size();
    if(n < 2) return "";
    vector<int> sub(n,0);
    sub[0] = ((s[0]=='0')?(-1):1);
    for(int i=1;i<n;++i)
        sub[i] = sub[i-1] + ((s[i]=='0')?(-1):1);
    for(auto a: sub) cout << a << " "; cout << endl;
    string ans;
    unordered_map<int,P> ex;
    for(int i=0;i<n;++i)
    {
      auto it = ex.find(sub[i]);
      if(it!=ex.end())
      {
        (*it).second.first = min((*it).second.first,i);
        (*it).second.second = max((*it).second.second,i);
      }
      else
      {
        if(sub[i] == 0) 
          ex.insert(make_pair(sub[i],make_pair(-1,i)));
        else
          ex.insert(make_pair(sub[i],make_pair(i,i)));
      }
    }
    for(auto a:ex)
        cout << a.first << " " << a.second.first << " " << a.second.second << endl; 
    for(auto a:ex)
    {
        int l =a.second.first, r = a.second.second;
        if(r-l >= ans.size()) ans = s.substr(l+1,r-l);
    }
    return ans;
}
int main(void)
{
    srand(time(nullptr));
    int k = 100;
    while(k--)
    {
        string s ;//= "0100010";
        const int n = rand()%10;
        for(int i=0;i<n;++i)
            s += (rand()%2+'0');
        cout << " s : " << s << endl;
        
        string ret = longest01(s);
        string ans = longest012(s);
        cout << "ret : " << ret << endl;
        cout << "ans : " << ans << endl;
        getchar();
    }
    return 0;
}
