#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

#include <limits.h>
#include <assert.h>

using namespace std;


 string minWindow(string S, string T) {
        string ret, cur;
        int sLen = S.size(), tLen = T.size();
        if(sLen == 0 || tLen > sLen) return string("");


        unordered_map<char, int> appeared;
        unordered_map<char, int> expected;

        for(int i = 0 ; i < tLen ; ++i)
        {
            if(expected.count(T[i]))
            {
                expected[T[i]] ++;
            }
            else
            {
                expected[T[i]] = 1;
            }
        }

        for(int i = 0 ; i < tLen ; ++i)
        {
            appeared[T[i]] = 0;
        }


        int current_count = 0;


        int l = 0 , r = INT_MAX;

        int left = 0, right = 0;

        while(right < sLen)
        {
            //is a char of t
            if(expected.find( S[right] ) != expected.end() )
            {
                appeared[S[right]]++;
                if(appeared[S[right]] <= expected[S[right]])
                    ++current_count;
            }

            if(current_count == tLen )
            {
                while( left <= right &&
                ( (expected.find(S[left]) != expected.end() && appeared[S[left]] > expected[S[left]])
                || (expected.find(S[left]) == expected.end() ) ))
                {
                    if(appeared.find(S[left])!= appeared.end())
                        appeared[S[left]]--;
                    ++left;
                }

                if( right - left < r - l )
                {
                    l = left;
                    r = right;
                }
            }
            ++right;
        }

        if(r - l > sLen)
            return string("");

        return S.substr(l,r-l+1);
    }

int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << minWindow (S,T) << endl;
    return 0;
}
