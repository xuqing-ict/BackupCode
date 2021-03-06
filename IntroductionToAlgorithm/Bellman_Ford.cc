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

struct edge
{
    int from,to,cost;
    edge(int _from=-1 , int _to=-1, int _cost=INF):from(_from),to(_to),cost(_cost){}
};

vector<edge> G;
int d[MAX_V];
int V,E,S;

void buildWeightedGraph()
{
  scanf("%d %d %d",&V,&E,&S);
  for(int i=0;i<E;++i)
  {
    int s,t,w;
    scanf("%d %d %d",&s,&t,&w);
    G.push_back(edge(s,t,w));
  }
  for(int i=0;i<G.size();++i)
  {
      cout << "edge : " << G[i].from << "\t" << G[i].to << "\t" << G[i].cost << endl;
  }
  return;
}

bool hasNegativeCircle()
{
  memset(d,0,sizeof(d));
  for(int i=0;i<V;++i)
  {
    for(int j=0;j<E;++j)
    {
        edge e = G[j];
        if(d[e.to] > d[e.from] + e.cost)
            d[e.to] = d[e.from]+e.cost;
        if(i== V-1) return true;
    }
  }
  return false;
}

void bellman_ford(int s)
{
    fill_n(d,MAX_V,INF);
    d[s]=0;
  //detect the negete circle
  if(hasNegativeCircle())
  {
    cout << "hasNegativeCircle..." << endl;
    return;
  }
  else
  {
    for(int i=0;i<V;++i)
    {
      bool update=false;
      for(int j=0;j<E;++j)
      {
        edge e = G[j];
        if(d[e.to] > d[e.from] + e.cost)
        {
            d[e.to]=d[e.from]+e.cost;
            update=true;
        }
      }
      if(!update)break;
    }
        for(int i=0;i<V;++i)
            cout << d[i] << "\t";
        cout << endl;
  }
}
int main()
{
    buildWeightedGraph();
    if(hasNegativeCircle())
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        bellman_ford(0);
        cout << V << endl;
        for(int i=0;i<V;++i)
            cout << d[i] << "\t";
        cout << endl;
    }
  return 0;
}
