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

int cost[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
int V,E,S; // the number of vertex

void Floyd_Warshall()
{
  fill_n(&d[0][0],MAX_V*MAX_V,INF);
  //init
  for(int i=0;i<V;++i)
  {
    for(int j=0;j<V;++j)
    {
      d[i][j]=cost[i][j];
    }
  }
  for(int i=0;i<V;++i)
      d[i][i]=0;
  for(int k=0;k<V;++k)
  {
    for(int i=0;i<V;++i)
    {
      for(int j=0;j<V;++j)
      {
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  cout << "xq" << endl;
  for(int i=0;i<V;++i)
  {
    for(int j=0;j<V;++j)
      cout << d[i][j] << "\t";
    cout << endl;
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
  for(int i=0;i<V;++i)
      for(int j=0;j<V;++j)
          if(cost[i][j] < INF)
            cout << i << "\t" << j << "\t" << cost[i][j] << endl;
  return;
}



int main()
{
    buildWeightedGraph();
    Floyd_Warshall();
    return 0;
}
