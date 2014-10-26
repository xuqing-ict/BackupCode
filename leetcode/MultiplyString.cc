#include <bits/stdc++.h>
using namespace std;


vector<int> toInt(const string &s)
{
    if(s.empty()) return vector<int>();
    vector<int> ret;

    for(int i=0;i<s.size();++i)
        ret.push_back(s[i] - '0');
    return ret;
}

string toStr(const vector<int> &num)
{
    string ret;
    for(int i=0;i<num.size();++i)
        ret += num[i] +'0';
    return ret;
}
string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    if(n1 == 0 || n2 == 0)
    {
        cerr << "Input paramter illegal!!!" << endl;
        exit(1);
    }

    bool label = false;
    //+ /-
    int i=0,j=0;
    if(num1[0] == '-' || num2[0] == '-')
    {
        if(num1[0] == '-') {label = !label; ++i;}
        if(num2[0] == '-') {label = !label; ++j;}
    }
    string s1_t = num1.substr(i);
    string s2_t = num2.substr(j);
    cout << s1_t << "\t" << s2_t << endl;

    const int len1 = s1_t.size(), len2 = s2_t.size();
    reverse(s1_t.begin(),s1_t.end());
    reverse(s2_t.begin(),s2_t.end());
    cout << s1_t << "\t" << s2_t << endl;

    vector<int> s1 = toInt(s1_t), s2 = toInt(s2_t);
    vector<int> ret(len1+len2,0);

    for(int i=0;i<s1.size();++i)
    {
        for(int j = 0; j < s2.size();++j)
        {
            ret[i+j] += s1[i]*s2[j];
            ret[i+j+1] += ret[i+j]/10;
            ret[i+j] %= 10;
    cout << "ret : " ;
    for(int i=0;i<ret.size();++i)
        cout << ret[i] << "\t";
    cout<< endl;
        }
    }
    cout << "ret : " ;
    for(int i=0;i<ret.size();++i)
        cout << ret[i] << "\t";
    cout<< endl;
    
    //去掉末尾的0
    i=ret.size()-1;
    for(i=ret.size()-1;i>=0;--i)
    {
        if(ret[i]!=0) break;
    }
    ret.resize(i+1);
    reverse(ret.begin(),ret.end());
    string ret_s = toStr(ret);
    if(label) ret_s = '-' + ret_s;
    return ret_s;
}
int main(void)
{
    string s1 = "243", s2 = "977";
    vector<int> ret = toInt(s1);
    cout << multiply(s1,s2) << endl;
    return 0;
}
