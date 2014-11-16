
#include <bits/stdc++.h>
using namespace std;

int FirstOnceChar(const string &s)
{
    const int  n = s.size();
    int exist[256];
    fill_n(&exist[0],256,0);
    for(int i=0;i<n;++i)
        exist[s[i]]++;
    for(int i=0;i<n;++i)
        if(exist[s[i]] == 1)
            return i;
    return -1;
}

void deleteSpecificChar(string &s, const string &t)
{
    const int n = s.size();
    if(t.size() == 0 || s.size() == 0) return ;
    vector<bool> illegal(256,false);
    for(int i=0;i<t.size();++i)
        illegal[t[i]]=true;
    int cur=0;
    for(int i=0;i<n;++i)
    {
        if(!illegal[s[i]]) s[cur++]=s[i];
    }
    s.erase(s.begin()+cur,s.end());
    cout << s << endl;
    return;
}


void deleteDuplicates(string &s)
{
    const int n = s.size();
    if(s.size() == 0) return ;
    vector<bool> exist(256,false);

    int cur=0;
    for(int i=0;i<n;++i)
    {
        if( exist[s[i]] == false )
        {
            s[cur++] = s[i];
            exist[s[i]] = true;
        }
    }
    s.erase(s.begin()+cur,s.end());
    cout << s << endl;
    return;
}


int main(void)
{

    string s = "google";
    deleteDuplicates(s);
/*    string s = "We are students.";
    const string t = "aou.";
    deleteSpecificChar(s,t);

    string s;
    while(cin >> s)
    {
        cout << FirstOnceChar(s) << endl;
    }*/
    return 0;
}
