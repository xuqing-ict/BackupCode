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
using namespace std;

//从word开始到start的所有路径
void buildPaths(map<string, vector<string> > & parent, string start , string word, vector<string> &curPath , vector<vector<string> > & ret)
{
	curPath.push_back(word);
	if(word == start)
	{
		ret.push_back(curPath);
		return;
	}

	for(map<string, vector<string> >::iterator it = parent[word].begin() ; it != parent[word].end(); ++it)
	{
		buildPaths(parent, start, *it, curPath, ret);
	}
	curPath.pop_back();
			

}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string > > ret;
	unordered_set<string> prev, next;

	unordered_set<string> visited;
	map<string, vector<string> > parent;


	prev.insert(start);

	string curWord , tempWord;
	
	bool found = false;

	while(!prev.empty())
	{
		for(unordered_set<string>::iterator it = prev.begin() ; it != prev.end(); ++it)
		{
			curWord = *it;
			visited[curWord] = true;

			for(int i = 0 ; i < curWord.size() ; ++i)
			{
				tempWord = curWord;
				for(char c = 'a'; c <= 'z'; ++c)
				{
					if(curWord[i] == c)
					{
						continue;
					}
					tempWord[i] = c;
					if (tempWord == end)
					{
						found = true;
					}
					if (visited[tempWord] == 0  && (dict.count(tempWord) != 0 || tempWord == end))
					{
						visited.insert(tempWord);
						parent[tempWord].append(curWord);
					}
					tempWord = curWord;
				}
			}
		}
		if(found)
		{
			vector<string> curPath;
			buildPaths(parent, start,end, curPath, ret);
			return ret;
		}
		prev.clear(); //!!!
		swap(prev,next);
	}
	return ret;
}


int main()
{
	string	start = "hit"
	string end = "cog"
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	dict.insert("lot");
	dict.insert("log");
	vector<vector<string > > ret = wordLadder(start,end,dict);
	return 0;
}




