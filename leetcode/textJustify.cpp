#include <bits/stdc++.h>
using namespace std;

string paddle(string cur, int cur_count, const int max_len)
{

    cur.resize(cur.size()-1); //cut the last ' '
    assert(cur.size() <= max_len);
    if(cur_count == 1) return cur;
    //return cur;

    string ret;
    ret.resize(max_len);

    int left = max_len-cur.size();
    int index=0;
    int  i = 0;

    int each = left/(cur_count-1);
    int other = left % (cur_count-1);

    for(int i = 0 ; i < cur.size(); ++i)
    {
        ret[index++] = cur[i];
        int temp = each;
        if(cur[i] == ' ')
        {
            while(temp-- > 0) ret[index++] = ' ';
            if(other)
            {
                ret[index++] = ' ';
                --other;
            }
        }
    }
    return ret;
}
    vector<string> fullJustify(vector<string> &words, int L) {
        if(words.empty() || L <= 0) return vector<string>();
        //divide according to L

        vector<string> ret;
        string cur;
        int cur_len = 0, cur_count = 0;
        for(int i = 0 ; i < words.size(); ++i)
        {
            int len =  words[i].size();
            if(cur_len + words[i].size() > L)
            {
                cur = paddle(cur,cur_count,L);
                ret.push_back(cur);
                cur.clear();
                cur_len = 0;
                cur_count = 0;
            }
            cur += words[i];
            cur += ' ';
            cur_len += (words[i].size()+1);
            cur_count += 1;
        }

        if(!cur.empty())
        {
            int left = L - cur.size();
            while(left-->0) cur += ' ';
            ret.push_back(cur);
        }
        return ret;
    }
    int main()
    {
        //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
       vector<string> words ={"Listen","to","many,","speak","to","a","few."};
       // vector<string> words(1,"");
        vector<string> ret = fullJustify(words,6);
        for(int i = 0 ; i< ret.size(); ++i)
            cout << ret[i].size() << "\t" << ret[i] << endl;

        return 0;

    }
