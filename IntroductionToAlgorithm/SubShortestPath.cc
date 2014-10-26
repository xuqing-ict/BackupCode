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

//很简单，只是需要保存每一个节点的最短路以及次短路即可！！！
//version 2 : Adjacent links and priortity queue

struct edge
{
    int from,to,cost;
    edge(int _from=-1 , int _to=-1, int _cost=INF):from(_from),to(_to),cost(_cost){}
};

vector<edge> G[MAX_V];
int d[MAX_V];
int d2[MAX_V]; //sub shortest path
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
    if(S==false)
      G[t].push_back(edge(t,s,w));
  }
  return;
}
void dijsktra()
{
  cout << V << "\t" << E << endl;
  fill_n(d,MAX_V,INF);
  fill_n(d2,MAX_V,INF);
  d[0]=0;

  priority_queue<Pair,vector<Pair>,greater<Pair> > que; //select the minimum distance between S and V-S
  que.push(Pair(0,0)); //(dis, node) pair , so we do not need to overload the operator> of pair
  while(!que.empty())
  {
    Pair p = que.top();que.pop(); //(dis, node) pair
    int v=p.second, dis=p.first;
    if(d2[v] < dis)continue; //overdue value
    for(int i=0;i<G[v].size();++i)
    {
      edge e=G[v][i];
      int new_dis = dis+e.cost;
      //update shortest path
      if(d[e.to] > new_dis)
      {
        //swap(d[e.to],new_dis);
        int tmp=new_dis;
        new_dis=d[e.to];
        d[e.to]=tmp;
        que.push(Pair(d[e.to],e.to));
      }
      //update sub shortest path
      //如果当前的第二值比要更新的值大，并且最小值比当前值小，那么就更新第二小的值。。。
      //很显然，如果当前的最小值就是new_dis，那么第二值就不应该更新。
      if(d2[e.to] > new_dis && d[e.to] < new_dis)
      {
        d2[e.to]=new_dis;
        que.push(Pair(d2[e.to],e.to));
      }
    }
  }
  for(int i=0;i<V;++i)
      cout << d[i] << "\t" << d2[i] << endl;
  cout << "Final result : " << d2[V-1] << endl;
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
