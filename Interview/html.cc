/**
 * @file html.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-11
 */
#include <bits/stdc++.h>
using namespace std;

map<string,string> label;

vector<string> convert(const vector<string> &A)
{
    vector<string> ret;
    string line;
    for(int i=0;i<A.size();++i)
    {
        if(A[i] == "<br>" || A[i] == "<hr>")
        {
            if(A[i] == "<br>")
            {
                ret.push_back(line);
                line = "";
            }
            if(A[i] == "<hr>")
            {
                if(!line.empty())
                {
                    ret.push_back(line);
                    line = "";
                    ret.push_back(label["<hr>"]);
                }
                else
                {
                    ret.push_back(label["<hr>"]);
                }
            }
        }
        else
        {
            if(line.size() + 1 + A[i].size() > 80)
            {
                ret.push_back(line);
                line = "";
                line += A[i];
            }
            else
            {
                if (!line.empty())
                    line += ' ';
                line += A[i];
            }
        }
    }
    if(!line.empty())ret.push_back(line);
    return ret;
}

int main(void)
{
    string tmp(80,'-');
    label.insert(make_pair("<br>","\n"));
    label.insert(make_pair("<hr>",tmp));

    string s;
    vector<string> input;
    while(cin >> s)
    {
        input.push_back(s);
    }

    vector<string> ret = convert(input) ;
    for(int i=0;i<ret.size();++i)
        cout << ret[i]  << endl;

    return 0;
}
