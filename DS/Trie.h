// Last Update:2014-11-18 11:32:31
/**
 * @file Trie.h
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-18
 */

#ifndef _TRIE_H
#define _TRIE_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <memory.h>

using namespace std;

class Trie
{
const static int branchNum = 26;
private:
    struct Node
    {
        bool isStr;
        Node *next[branchNum];
        Node():isStr(false)
        {
            memset(next,0,sizeof(next));
        }
    };

    Node *root;
    static size_t cnt ; // count the number of nodes of the trie tree

private: //private function
    void destory(Node * &root);
    string tolower(const string &s);
public:
    //ctor
    Trie():root(new Node()){}
    ~Trie()
    {
        destory(root);
    }
    void insert(const string &str);
    bool search(const string &str) const;
    void build(const string &file);
};

size_t Trie::cnt = 0;
string Trie::tolower(const string &s)
{
    string ret;
    for(auto a:s) ret += std::tolower(a);
    return ret;
}

void Trie::destory(Node * &root)
{
    for(int i=0;i<branchNum;++i)
    {
        if(root->next[i])
            destory(root->next[i]);
    }
    delete root;
    root = nullptr;
}
void Trie::insert(const string &Str)
{
    if(Str.empty()) return;
    string str = tolower(Str);
    Node *tmp = root;
    auto it = str.begin();
    for(;it!=str.end();++it)
    {
        if(tmp->next[*it-'a'])
            tmp = tmp->next[*it-'a'];
        else 
            break;
    }
    //add node
    for(;it!=str.end();++it)
    {
        tmp->next[*it-'a'] = new Node();
        tmp = tmp->next[*it-'a'];
        ++cnt;
    }
    tmp->isStr = true;
}
bool Trie::search(const string &s) const
{
    if(s.empty())
    {
        cout << "search empty word..." << endl;
        return true;
    }
    Node *tmp = root;
    auto it = s.begin(); 
    for(;it!= s.end(); ++it)
    {
        if(tmp->next[*it-'a']) tmp = tmp->next[*it-'a'];
        else break;
    }
    if(it == s.end() && tmp->isStr == true) return true;
    return false;
}
void Trie::build(const string &file)
{
    ifstream in(file.c_str());
    if (!in)
    {
        cerr << "No such file or directory..." << endl;
        exit(1);
    }
    string word;
    while(getline(in,word))
    {
        insert(word);
    }
}

#endif  /*_TRIE_H*/
