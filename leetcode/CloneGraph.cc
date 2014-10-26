/**
 * @file CloneGraph.cc
 * @brief clone graph
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-11
 */

#include <bits/stdc++.h>
using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == nullptr) return nullptr;
    vector<UndirectedGraphNode*> h; // record the first visit node but have not add their children
    h.push_back(node);
    unordered_map<int,UndirectedGraphNode*> exist;
    exist[node->label]=new UndirectedGraphNode(node->label);
    for(int i=0;i<h.size();++i)
    {
      UndirectedGraphNode *x=exist[h[i]->label];
      for(int j=0;j<h[i]->neighbors.size();++j)
      {
        UndirectedGraphNode *nei = (h[i]->neighbors)[j];
        //first visit the node add to h
        if(exist.find(nei->label) == exist.end())
        {
          exist[nei->label]=new UndirectedGraphNode(nei->label);
          h.push_back(nei);
        }
        x->neighbors.push_back(exist[nei->label]);
      }
    }
    return exist[node->label];
}

UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
    if(node == nullptr) return nullptr;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    unordered_set<UndirectedGraphNode *> done;
    unordered_map<int, UndirectedGraphNode *> exist;
    UndirectedGraphNode *ret=nullptr;
    while(!q.empty())
    {
      UndirectedGraphNode *cur=q.front();q.pop();
      if(done.find(cur)!=done.end())
          continue;

      //first process the node
      UndirectedGraphNode *parent=nullptr;
      if(exist.find(cur->label) == exist.end())
      {
        UndirectedGraphNode *tmp=new UndirectedGraphNode(cur->label);
        if(tmp->label == node->label) ret=tmp;
        exist.insert(make_pair(cur->label,tmp));
      }
      assert(exist[cur->label]);
      parent=exist[cur->label];

      for(int i=0;i<(cur->neighbors).size();++i)
      {
          auto it2=exist.find(((cur->neighbors)[i])->label);
          if(it2 != exist.end())
          {
              (parent->neighbors).push_back(it2->second);
          }
          else
          {
            UndirectedGraphNode *tmp = new UndirectedGraphNode(cur->neighbors[i]->label);
            (parent->neighbors).push_back(tmp);
            exist.insert(make_pair(cur->neighbors[i]->label,tmp));
          }
          q.push((cur->neighbors)[i]);
      }
      done.insert(cur);
    }
    return ret;
}

int main(void)
{
  UndirectedGraphNode *node= new UndirectedGraphNode(-1);
  UndirectedGraphNode *node1= new UndirectedGraphNode(1);
  node->neighbors.push_back(node1);
  node1->neighbors.push_back(node);
  cloneGraph2(node);

  return 0;
}

