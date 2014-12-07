#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include <limits.h>
#include <unordered_set>
using namespace std;

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void helper(string start, const string &end, unordered_set<string> &dict,int curStep, int &minStep, int curPos)
{
    if(minStep < curStep)
    {
        cout << "xq2" << endl;
        return;
    }
    if(start == end)
    {
        cout << "xq" << endl;
        if(curStep < minStep)
        {
            minStep = curStep;
        }
        return;
    }

    for(int j = 0 ; j < 26; ++j)
    {
        for(int i = 0 ; i < end.size() && 1 != curPos ; ++i)
        {
            string temp = start;
            temp[i] = alphabet[j];
            if(dict.find(temp) != dict.end())
            {
                cout << temp << " in dict..." << endl;
                curPos = i;
                helper(temp, end, dict, curStep+1, minStep, curPos);
            }
            else
            {

            }
        }
    }
}

int ladderLength(string start, string end, unordered_set<string> &dict)
{
    if(dict.size()  == 0  || start ==  end)
    {
        return 0;
    }
    int curStep = 0;
    int minStep = INT_MAX;
    helper(start, end, dict, curStep, minStep,-1);
    return minStep;
}
int main()
{
    unordered_set<string> dict;
   // "hot","dot","dog","lot","log"
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    string start = "hit";
    string end = "cog";

    cout << ladderLength(start,end ,dict) << endl;
    return 0;
}
