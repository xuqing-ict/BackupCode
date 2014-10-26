/**
 * @file Trie.cc
 * @brief Trie tree
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26;

struct Node
{
    string word;
    bool hasChild;
    struct Node *childs[SIZE];
    Node(string _word=""):word(_word)
    {
      hasChild=false;
      for(int i=0;i<size;++i)
          childs[i]=nullptr;
    }
}TrieNode;


class TrieTree
{
private:
    TrieNode *root;
    void destory();
public:
    TrieTree();
    ~TrieTree();
    void insert(const string &);
    bool search();
};

TrieTree::TrieTree()
{
  root = new TrieNode();
}
TrieTree::~TrieTree()
{
    destory(root);
}
TrieTree::destory(TrieNode *cur)
{
  if(cur==nullptr) return;
  for(int i=0;i<SIZE;++i)
  {
    destory(cur->childs[i]);
  }
  delete cur;
}

void TrieTree::insert(const string &cur)
{
  if(cur.empty()) return;
  TrieNode *parent=root, *child=nullptr;
  for(int i=0;i<cur.size();++i)
  {
      child = root->childs[cur[i]-'a'];
      if(child==nullptr)
      {
        TrieNode *node = new TrieNode(cur[i]);
        root->childs[cur[i]-'a'] =
      }
    
  }
}
int main(void)
{
  vector<string> dict;
  string word;
  while(cin >> word)
  {
    dict.push_back(word);
  }
  cout << "dict size : " << dict.size() << endl;
  Trie
  return 0;
}
