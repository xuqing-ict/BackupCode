#include <bits/stdc++.h>
using namespace std;


bool valid(const string &s)
    {
        if(s.size() == 1) return true;
        return (!s.empty() && s[0] != '0' && atoi(s.c_str()) >= 0 && atoi(s.c_str()) <= 255 );
    }

    void helper(const string &s, int cur_index, const int max_index, string &cur, int count, vector<string> &ret)
    {
        if(cur_index > max_index || count >= 4 )
        {
            if(count == 4) ret.push_back(cur);
            return;
        }

        for(int i=1;i<=3;++i)
        {
            string backup = cur;
            string tmp = s.substr(cur_index,i);
            if(valid(tmp))
            {
                if(!cur.empty())cur += '.';
                cur += tmp;
                helper(s,cur_index+i,max_index,cur,count+1,ret);
            }
            cur=backup;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        const int n = s.size();
        if(n == 0 || n > 12) return vector<string>();
        vector<string> ret;
        string cur;
        helper(s,0,n-1,cur,0,ret);
        return ret;
    }
int main(void)
{
    string s = "0000";
    vector<string> ret = restoreIpAddresses(s);
    for(auto a: ret)
        cout << a << endl;
    cout << endl;
}
