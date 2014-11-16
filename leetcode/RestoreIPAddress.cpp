#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

bool isSafety(const int number , const string str)
{
    cout << number << " " << str << endl;
    if(str.size() == 1 )
    {
        return true;
    }
    if(!str.empty() && str[0] != '0' && number >= 0 && number <= 255)
    {
        return true;
    }
    return false;
}
void helper(const string &s,  int curIndex, int curLen, int maxIndex, string &curString, vector<string> &ret)
{
    if( curLen > 4 )
    {
        return;
    }
    if(curLen == 4 && curIndex > maxIndex)
    {
        ret.push_back(curString);
        return;
    }

    for(int i = 1 ; i <= min(3, maxIndex - curIndex + 1) ; ++i)
    {
        string temp = s.substr(curIndex, i);
        int curNumber = atoi(temp.c_str());
        //cout << temp << " " << curNumber << endl;
        if(isSafety(curNumber, temp))
        {
            int tLen = 0;
            if(!curString.empty())
            {
                curString += '.';
                tLen += 1;
            }
            curString += temp;
            tLen += i;
            helper(s, curIndex + i, curLen+1, maxIndex, curString, ret);
            curString.resize(curString.size() - tLen);
        }
    }
}
vector<string> Restore(string s)
{
    vector<string> ret;
    if(s.empty())
    {
        return ret;
    }
    string curString;
    helper(s,0,0,s.size()-1, curString,ret);
}

int main()
{
    string s = "010010";
    vector<string> ret =  Restore(s);
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout,"\t"));
    cout << endl;
    return 0;
}
