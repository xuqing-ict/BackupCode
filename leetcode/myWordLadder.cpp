/*
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

void buildPaths(map<string, vector<string> > & parent, const string &start , const string word, vector<string> &curPath , vector<vector<string> > & ret)
{
    //首先将word加入path
    curPath.push_back(word);
	if(word == start)
	{
	    cout << "xq" << endl;
		ret.push_back(curPath);
		reverse(ret[ret.size()-1].begin(), ret[ret.size()-1].end() );
	}
    else
    {
	    for(int i  = 0 ; i < parent[word].size() ; ++i )
	    {
		    buildPaths(parent, start, parent[word][i], curPath, ret);
	    }
    }
    curPath.pop_back();

}


vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string > > ret;
	queue<string> prev, next;

	unordered_set<string> visited;
	map<string, vector<string> > parent;

	prev.push(start);

	string curWord , tempWord;

	bool found = false;

	while(!prev.empty())
	{
	    while(!prev.empty())
	    {
	        curWord = prev.front();
	        prev.pop();

            visited.insert(curWord);
            tempWord = curWord;
            for(int i = 0 ; i < curWord.size() ; ++i)
	        {
				tempWord = curWord;
				for(char c = 'a' ; c <= 'z' ; ++c)
				{
				    tempWord = curWord;
					if(curWord[i] == c)  continue;

					tempWord[i] = c;
					//find at current level
					if (tempWord == end )
					{
						found = true;
						parent[end].push_back(curWord);
					}
					else if( visited.find(tempWord) != visited.end() && dict.find(tempWord) != dict.end())
					{
						visited.insert(tempWord);
						parent[tempWord].push_back(curWord);
						next.push(tempWord);
					}

				}
		    }
	    }
		//if(found || next.empty() )break;
		swap(prev,next);
	}

    if(found)
    {
        vector<string> curPath;
        buildPaths(parent, start, end, curPath, ret);
        //return ret;
    }
	return ret;
}

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	dict.insert("lot");
	dict.insert("log");

	vector<vector<string > > ret = findLadders(start,end,dict);
	for(vector<vector<string> > ::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
	    copy(it->begin(), it->end(), ostream_iterator<string>(cout,"\t"));
	    cout << endl;
	}
	return 0;
}




