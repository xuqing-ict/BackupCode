#include <bits/stdc++.h>
using namespace std;

vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void helper(const string digits, int cur_index, string cur, const int max_index, vector<string> &ret)
{
    if(cur_index > max_index)
    {
        ret.push_back(cur);
        return ;
    }
    string temp = dict[digits[cur_index]-'0'];
    for(int i = 0 ; i < temp.size(); ++i)
    {
        cur.push_back(temp[i]);
        helper(digits,cur_index+1, cur, max_index, ret);
        cur.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if(digits.empty()) return vector<string>();
    vector<string> ret;
    const int n = digits.size();
    string cur;
    helper(digits,0,cur,n-1,ret);
    return ret;
}

int main()
{
    string digits = "23";
    vector<string> ret = letterCombinations(digits);
    for(auto a: ret)
        cout << a << endl;
    return 0;
}

