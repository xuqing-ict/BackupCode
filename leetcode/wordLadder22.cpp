#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

void buildPath( map<string, vector<string> > & parent, const string start, string word,
               vector<string > &curPath, vector<vector<string> > &ret)
{
   // cout << "build path..." << endl;
    curPath.push_back(word);
    if(word == start)
    {
        ret.push_back(curPath);
        reverse(ret.back().begin(), ret.back().end());
    }
    else
    {

        for(int i = 0 ; i < parent[word].size() ; ++i)
        {
            buildPath( parent, start, ret, curPath, parent[word][i]);
        }

    }
    curPath.pop_back();
}

vector< vector< string> > findLadders( string start, string end, unordered_set<string> & dict)
{
    vector<vector<string > > ret;
    if(start == end || dict.empty()) return ret;

    set<string>prev, next;
    prev.insert(start);

    set<string> visited;
    bool found;
    map<string, vector<string> > parent;

    while(!prev.empty())
    {
        for(auto word : prev)
            visited.insert(word);
        for(auto word : prev)
        {
            for(int i = 0 ; i < word.size(); ++i)
            {
                for(char c = 'a' ; c <= 'z' ; ++c)
                {
                    if(c == word[i]) continue;
                    string new_word = word;
                    new_word[i] = c;
                    if(new_word == end) found = true;
                    if(visited.count(new_word) == 0 && (dict.count(new_word) > 0 || new_word == end))
                    {
                        parent[new_word].push_back(word);
                    }
                    new_word = word;
                }
            }
        }
        if(found)
        {
            vector<string> path;
            buildPath(parent, start, end, path, ret);
            return ret;
        }
    }
    return ret;
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

    vector<vector<string> > ret = findLadders(start, end, dict) ;
    cout << "result : " << endl;

    for(int i = 0 ; i < ret.size() ; ++i)
    {
        copy(ret[i].begin(), ret[i].end(), ostream_iterator<string>(cout,"\t"));
        cout << endl;
    }

}
