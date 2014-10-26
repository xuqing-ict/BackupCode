/**
 * @file biGraph.cc
 * @brief shortest path
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 10;
const int MAX_E = 100;
const int INF = 1000;
/*
//version 1 : using adjacent matrix
int cost[MAX_V][MAX_V];
int used[MAX_V];
int d[MAX_V];
int V,E,S; // the number of vertex

void dijsktra()
{
  fill_n(used,MAX_V,false);
  fill_n(d,MAX_V,INF);
  d[0]=0;
  while(true)
  {
    int v=-1;
    for(int i=0;i<V;++i)
    {
      if(used[i]==false && (v==-1 || d[i]<d[v])) v=i;
    }
    if(v==-1) break;
    used[v]=true;
    //update the adjacent vertices of v
    for(int i=0;i<V;++i)
    {
      d[i]=min(d[i],d[v]+cost[v][i]);
    }
  }
}

void buildWeightedGraph()
{
  fill_n(&cost[0][0],MAX_V*MAX_V,INF);
  scanf("%d %d %d",&V,&E,&S);
  for(int i=0;i<E;++i)
  {
    int s,t,w;
    scanf("%d %d %d",&s,&t,&w);
    cost[s][t]=w;
  }
  return;
}



int main()
{
    buildWeightedGraph();
    dijsktra();
        cout << V << endl;
        for(int i=0;i<V;++i)
            cout << d[i] << "\t";
        cout << endl;
  return 0;
}
*/
//version 2 : Adjacent links and priortity queue

struct edge
{
    int from,to,cost;
    edge(int _from=-1 , int _to=-1, int _cost=INF):from(_from),to(_to),cost(_cost){}
};

vector<edge> G[MAX_V];
int d[MAX_V];
int d2[MAX_V];
int V,E,S;

typedef pair<int,int> Pair;

void buildWeightedGraph()
{
  scanf("%d %d %d",&V,&E,&S);
  for(int i=0;i<E;++i)
  {
    int s,t,w;
    scanf("%d %d %d",&s,&t,&w);
    G[s].push_back(edge(s,t,w));
  }
  return;
}
void dijsktra()
{
  fill_n(d,MAX_V,INF);
  fill_n(d2,MAX_V,INF);
  d[0]=0;

  priority_queue<Pair,vector<Pair>,greater<Pair> > que; //select the minimum distance between S and V-S
  que.push(Pair(0,0)); //(dis, node) pair , so we do not need to overload the operator> of pair
  while(!que.empty())
  {
    Pair p = que.top();que.pop();
    int v = p.second ; // the minimum distance
    if(d[v] < p.first) continue ; //!!!!Very impotant!!
    for(int i=0; i<G[v].size();++i)
    {
        edge e = G[v][i];
      if(d[e.to] > d[v]+e.cost)
      {
        d[e.to]=d[v]+e.cost;
        que.push(Pair(d[e.to],e.to));
      }
    }
  }
}

int main()
{
    buildWeightedGraph();
    dijsktra();
        cout << V << endl;
        for(int i=0;i<V;++i)
            cout << d[i] << "\t";
        cout << endl;
  return 0;
}
