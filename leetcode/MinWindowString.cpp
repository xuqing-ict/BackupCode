#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;


 string minWindow(string S, string T) {
        string ret, cur;
        int  i = 0;
		int n = S.size();
        unordered_set<char> exist;
        for(i = 0 ; i < T.size() ; ++i)
            exist.insert(T[i]);
            
        i = 0;
        int left, right;
        
        while( i < n)
        {
            while(i < n && exist.count(S[i]) == 0) ++i;
            if(i == n) break;
            exist.erase(S[i]);
            
            left = i;
            ++i;
            
            while(i < n && !exist.empty())
            {
                if(exist.count(S[i]) > 0 )
                {
                    exist.erase(S[i]);
                }
                ++i;
            }
            if(exist.empty())
            {
                right = i;
                cur = S.substr(left, right-left);
				cout << left << " " << right << " " << cur << endl;
                if(ret.empty() || cur.size() < ret.size())
                {
                    ret = cur;
                }
                for(int j = 0 ; j < T.size() ; ++j)
                    exist.insert(T[j]);
            }
        }
        return ret;
    }
  int main()
{
	string S("ADOBECODEBANC");
	string T("ABC");
		 cout << minWindow(S,T) << endl;
}
