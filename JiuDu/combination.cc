#include <bits/stdc++.h>
using namespace std;

void combination(const vector<char> &vec, int cur_index, const int max_index, string &cur, vector<string> &ret)
{
    if(cur_index > max_index)
    {
        if(!cur.empty())ret.push_back(cur);
        return;
    }
    //select vec[cur_index]
    cur.push_back(vec[cur_index]);
    combination(vec,cur_index+1,max_index,cur,ret);
    cur.pop_back();
    combination(vec,cur_index+1,max_index,cur,ret);
}

ostream_iterator<string> out(cout,"\t");

int main(void)
{
    vector<char> vec = {'a','b','c'};
    vector<string> ret;
    string cur;
    const int max_index = vec.size()-1;
    combination(vec,0,max_index,cur,ret);
    cout << ret.size() << endl;
    copy(ret.begin(), ret.end(), out);
    cout << endl;
    return 0;
}
