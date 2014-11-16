#include <bits/stdc++.h>

using namespace std;

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void printPath( unordered_map<string, vector<string> > & parent, const string start, vector<vector<string> > &ret,
               vector<string > &curPath, const string word)
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
            printPath( parent, start,ret, curPath, parent[word][i]);
        }

    }
    curPath.pop_back();
}


vector< vector< string> > findLadders( string start, string end, unordered_set<string> & dict){
    vector<vector<string> > ret;
    if(start.size() != end.size() || dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end()) return ret;
    unordered_set<string> visited;
    unordered_map<string, vector<string> > parent;
    //ШЅжи
    unordered_set<string> prev,next;
    const int n = start.size();
    prev.insert(start);
    bool  found=false;
    while(!prev.empty())
    {
            for(auto a:prev) visited.insert(a);
            for(auto it=prev.begin();it!=prev.end();++it)
            {
                string cur=*it;
                for(int i=0;i<n;++i)
                {
                    string tmp=cur;
                    for(int j=0;j<26;++j)
                    {
                        char c = alphabet[j];
                        if(tmp[i] == c) continue;
                        swap(tmp[i],c);
                        if(tmp == end) found=true;
                        if(dict.find(tmp) != dict.end() && visited.find(tmp)==visited.end())
                        {
                            parent[tmp].push_back(cur);
                            next.insert(tmp);
                        }
                        swap(tmp[i],c);
                    }
                }
            }
            prev.clear();
        if(found)
        {
            vector<string> path;
            printPath(parent,start,ret,path,end);
            break;
        }
        next.swap(prev);
    }
    return ret;
    }
     bool isPalindrome(string s) {
        if(s.empty()) return true;
        string tmp;
        for(int i=0;i<s.size();++i)
        {
            if(isalpha(s[i]))tmp+=tolower(s[i]);
            if(isdigit(s[i]))tmp+=s[i];
        }
        cout << tmp << endl;
        const int n=tmp.size();
        int left=0,right=n-1;
        while(left<=right && tmp[left] == tmp[right]){++left;--right;}
        cout << left <<"\t" << right << endl;
        return left>=right;
    }
int main()
{
    unordered_set<string> dict;
   // "hot","dot","dog","lot","log"
   /* dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    string start = "hit";
    string end = "cog";
*/
//"lest","leet","lose","code","lode","robe","lost"]
    string start="leet",end2="code";
    dict.insert("lest");
    dict.insert("leet");
    dict.insert("lose");
    dict.insert("code");
    dict.insert("lode");
    dict.insert("robe");
    dict.insert("lost");
    vector<vector<string> > ret = findLadders(start,end2,dict);
    cout << ret.size() << endl;
    for(int i=0;i<ret.size();++i)
    {
        for(int j=0;j<ret[i].size();++j)
            cout<<ret[i][j] << "\t";
        cout << endl;
    }

       string s = "aA";
       cout << isPalindrome(s) << endl;
    return 0;
}
