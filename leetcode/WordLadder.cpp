#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include <limits.h>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;



const char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
    vector<vector< string > > paths;
    if(dict.size() == 0 || start == end)
    {
        return paths;
    }
    map<string, vector<string> > parent;
    //child[start] = string("");

    queue<string> prev;
    queue<string> next;

    unordered_set<string> visited;

    prev.push(start);

    string curWord, tempWord;
    bool found = false;

    while(!prev.empty())
    {
        while(!prev.empty())
        {
            curWord = prev.front();
            prev.pop();

            for(int i = 0; i < start.size(); ++i)
            {
                for(char c = 'a'; c <= 'z' ; ++c)
                {
                    tempWord = curWord;
                    if( curWord[i] == c)
                    {
                        continue;
                    }

                    if(curWord == end)
                    {
                        found = true;
                        /*
                        string word  = end;
                        vector<string> path;
                        path.push_back(start);

                        parent.insert(make_pai(end, curWord));

                        while(parent.find(word) != parent.end())
                        {
                            path.push_back(parent[word]);
                            word = parent[word];
                        }
                        paths.push_back(path);
*/
                        continue;
                    }
                    tempWord[i] = c;
                    if(dict.find(tempWord) != dict.end() && visited.find(tempWord) == visited.end())
                    {
                        parent.insert(make_pair(tempWord, curWord));
                        visited.insert(tempWord);
                    }
                }
            }
        }
        swap(prev, next);
        if(found)
        {
            break;
        }
    }
    return paths;
}




int main()
{
    unordered_set<string> dict;

   // "hot","dot","dog","lot","log"
//["hot","cog","dot","dog","hit","lot","log"]
//	"red", "tax", ["ted","tex","red","tax","tad","den","rex","pee"]
/*
    dict.insert("ted");
    dict.insert("tex");
    dict.insert("red");
    dict.insert("tax");
    dict.insert("tad");
    dict.insert("den");
    dict.insert("rex");
    dict.insert("pee");

    string start = "red";
    string end = "tax";

    */

    string start = "a";
    string end = "c";

    dict.insert("a");
    dict.insert("b");
    dict.insert("c");

//start to end the ladders
    vector<vector<string > > ret = findLadders(start, end, dict);

    cout << "DEBUG ret.size() " << ret.size() << endl;
    for(int i = 0 ; i < ret.size() ; ++ i)
    {
        copy(ret[i].begin(), ret[i].end(), ostream_iterator<string>(cout,"\t"));
        cout << endl;
    }
    return 0;
}
