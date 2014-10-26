/**
 * @file closestPair.cc
 * @brief the closest point pair in two-dimentinal space
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-01
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> Pair;
int N;
const int MAX_N = 10;
const int INF = INT_MAX;

Pair points[MAX_N];

bool cmp(const Pair &lhs, const Pair &rhs)
{
  return lhs.second < rhs.second;
}

double closestPair(Pair *p, const int n)
{
  if( n < 2) return INF;
  sort(p,p+n); //sort by x-dimention
  int m=n/2;
  Pair pivot=p[m];
  double d = min(closestPair(p,m),closestPair(p+m,n-m));
  
  inplace_merge(p,p+m,p+n,cmp);

  vector<Pair> occur;
  for(int i=0;i<n;++i)
  {
    if(fabs(p[i].first-pivot.first) > d) continue;
    for(int j=occur.size()-1;j>=0;--j)
    {
      double dx = occur[j].first - p[i].first;
      double dy = occur[j].second -p[i].second;
      if(fabs(dy) > d) break;
      d=min(d,sqrt(dx*dx+dy*dy));
    }
    occur.push_back(p[i]);
  }
  return d;
}
double closest(Pair *p, const int n)
{
  double ret=INF;
  for(int i=0;i<n;++i)
  {
      for(int j=i+1;j<n;++j)
      {
          double dx = p[j].first-p[i].first;
          double dy = p[j].second-p[i].second;
          ret=min(ret,sqrt(dx*dx+dy*dy));
      }
  }
  return ret;
}
int main(void)
{
  scanf("%d", &N);
  double x,y;
  cout << N << " points : ";
  for(int i=0;i<N;++i)
  {
      scanf("%lf\t%lf", &x, &y);
      cout << " ( " << x << "\t" << y << ") ";
      points[i] = make_pair(x,y);
  }
  cout << endl;
  cout << "result : " << closestPair(points,N) << endl;
  cout << "Answer : " << closest(points,N) << endl;
  return 0;
}
