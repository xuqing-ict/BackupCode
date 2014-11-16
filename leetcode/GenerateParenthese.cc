   #include <bits/stdc++.h>
   using namespace std;

    void helper(int lefts, int rights,const int n , string &cur, vector<string> &ret)
    {
        if(lefts < rights || lefts > n || rights > n) return;
        if(lefts == n && rights==n)
        {
            ret.push_back(cur);
            return;
        }
        //choose (
        cur.push_back('(');
        helper(lefts+1,rights,n,cur,ret);
        cur.pop_back();
        //choose )
        cur.push_back(')');
        helper(lefts,rights+1,n,cur,ret);
        cur.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        //each step, lefts >= rights
        vector<string> ret;
        if(n <= 0) return ret;
        int lefts=0, rights=0;
        string cur;
        helper(lefts,rights,n,cur,ret);
        return ret;
    }
    int main()
    {
        vector<string> ret=generateParenthesis(2);
        for(auto a: ret)
            cout << a << endl;
        return 0;
    }
