/**
 * @file Graph.cc
 * @brief graph BFS and DFS
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-26
 */

#include <bits/stdc++.h>
#include "Heap.h"

using namespace std;

const int MAX_V = 100;
vector<int> G[MAX_V];
int V,E,S;
int record=0;//record time

enum {WHITE=0,GRAY,BLACK};

int color[MAX_V];
int start[MAX_V];
int finish[MAX_V];

int dis[MAX_V];
int parent[MAX_V];
bool cycle=false;
int cost[MAX_V][MAX_V];
list<int> topo;

void buildGraph()
{
//int V,E,S;
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

void buildWeightedGraph()
{
  fill_n(&cost[0][0],MAX_V*MAX_V,0);
  bool di=false;
  scanf("%d %d %d",&V,&E, &S);
  if(S == 1) di = true;
  else di=false;

  for(int i=0;i<E;++i)
  {
    int s,t,w;
    scanf("%d %d %d",&s,&t,&w);
    G[s].push_back(t);
    if(di==false)G[t].push_back(s);
    cost[s][t] = w;
    cost[t][s] = w;
  }
  return;
}

void BFS(int s)
{
  fill_n(color,MAX_V,WHITE);
  fill_n(dis,MAX_V,0);
  queue<int> q;
  q.push(s);
  color[s]=GRAY;
  dis[s]=0;
  cout << "BFS : " << s << "\t"  << dis[s] << endl;
  while(!q.empty())
  {
      int s = q.front();
      q.pop();
      for(int i=0;i<G[s].size();++i)
      {
        if(color[G[s][i]] == WHITE)
        {
          q.push(G[s][i]);
          parent[G[s][i]]=s;
          color[s] = GRAY;
          dis[G[s][i]]=dis[s]+1;
          cout << G[s][i] << "\t" << dis[G[s][i]] << endl;
        }
      }
      color[s]=BLACK;
  }
  cout << endl;
}

void dfs(int s)
{
  cout << "dfs " << s << endl;
  color[s] = GRAY;
  ++record;
  start[s]=record;
  for(int i=0;i<G[s].size();++i)
  {
    if(color[G[s][i]]==WHITE)
    {
      parent[G[s][i]]=s;
      dfs(G[s][i]);
    }
    if(color[G[s][i]] == GRAY)
    {
      cycle=true;
    }
  }
  color[s]=BLACK;
  ++record;
  finish[s]=record;
  cout << "xq  topo " << s << endl;
  topo.insert(topo.begin(),s);
  cout << s << "\t" << start[s] << "\t" << finish[s] << endl;
}

void DFS()
{
  fill_n(color,MAX_V,WHITE);
  fill_n(start,MAX_V,0);
  fill_n(finish,MAX_V,0);
  fill_n(parent,MAX_V,-1);
  
  for(int i=0;i<V;++i)
  {
    if(color[i]==WHITE)
    {
      cycle=false;
      cout << "DFS" << endl;
      dfs(i); 
    }
  }
}

//Prim

void Prim(int start)
{
  Heap h;
  //record the cost of each node
  int min_cost[V];
  fill_n(min_cost, V,100);

  //record the node is in the MST or not
  bool used[V];
  fill_n(used,V,false);
  
  //record the prev node inserted to the MST
  bool parent[V];
  fill_n(parent,V,false);

  int total_cost=0; //record cost

  used[start] = true;
  min_cost[start]=0;
  h.push(make_pair(0,0));

  for(int i=1;i<V;++i)
  {
    h.push(make_pair(i,INT_MAX));
  }

  while(!h.empty())
  {
    Elem m = h.min(); 
    h.pop();

    int cur = m.first;
    used[cur]=true;
    total_cost += min_cost[cur];

    cout << "add node : " << cur << "\t" << total_cost << endl;

    for(int i=0;i<G[cur].size();++i)
    {
        int adj=G[cur][i];
        cout << "update " << cur << " adj : " << adj << endl;
        /*
        if( used[adj] == false && cost[cur][adj] < m.second)
        {
            parent[adj]=cur;
            h.decreaseKey(adj,cost[cur][adj]);
        }
        */
        if(used[adj] == false && min_cost[adj] > cost[cur][adj])
        {
              h.decreaseKey(adj,cost[cur][adj]);
              parent[adj] = cur;
              min_cost[adj]=cost[cur][adj];
              cout << "decrease " << cur << "\t" << adj << "\t" << cost[cur][adj] << endl;
        }
    }
  }
  cout << total_cost << endl;
}

int main()
{
    /*
  buildGraph();
  BFS(0);
  DFS();
  cout << "cycle : " << cycle << endl;
  cout << "topo : ";
  for(auto a:topo)
  {
      cout << a << "\t";
  }
  cout << endl;
  vector<pair<int,int> > v = {{1,2},{2,4},{3,3},{4,1}};
  Heap h(v.begin(), v.end());
  h.push(make_pair(5,-100));
  h.decreaseKey(2,-200);
  Elem min_elem = h.min();
  cout << min_elem.first << "\t" << min_elem.second << endl;
  h.pop();
  min_elem = h.min();
  cout << min_elem.first << "\t" << min_elem.second << endl;  
 */ 
  buildWeightedGraph();
  cout << V << "\t" << E << endl;
  for(int i=0;i<V;++i)
  {
      cout << i << " : " ;
      for(int j=0;j<G[i].size();++j)
        cout << G[i][j] << "\t";
      cout << endl;
  }
  Prim(0);
  return 0;
}
