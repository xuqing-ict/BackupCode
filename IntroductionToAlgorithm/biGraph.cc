/**
 * @file biGraph.cc
 * @brief biGraph or not 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;
vector<int> G[MAX_V];
int V,E,S;
int record=0;//record time

int color[MAX_V];

void buildGraph()
{
  bool di=false;
  scanf("%d %d %d",&V,&E, &S);
  if(S == 1) di = true;
  else di=false;

  for(int i=0;i<E;++i)
  {
    int s,t;
    scanf("%d %d ",&s,&t);
    G[s].push_back(t);
    if(di==false)G[t].push_back(s);
  }
  return;
}


bool dfs(int node, int val)
{
  color[node]=val;
  for(int i=0;i<G[node].size();++i)
  {
    if(color[G[node][i]]==val) return false;
    //do not color , color it with the other color
    if(color[G[node][i]]==0&& !dfs(G[node][i],-val))
        return false;
  }
  return true;
}

bool isBiGraph()
{
  fill_n(color,MAX_V,0);
  for(int i=0;i<V;++i)
  {
      if(color[i]==0)
      {
          cout << "dfs : " << i << endl;
          if(!dfs(i,1))
            return false;
      }
  }
  return true;
}

int main()
{
  buildGraph();
  if(isBiGraph())
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
