/**
 * @file 1018.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-27
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<(n);++i)
/*
typedef pair<int,int> P; //(brandth, price) pair
P mp[101][101];
int c[101]; //number of each devices
int t; //test case number
int n; //number of devices

bool cmp(const P & lhs, const P &rhs)
{
  return lhs.second < rhs.second;
}
//enumerate & cut

int main(void)
{
  scanf("%d",&t);
  while(t--)
  {
    fill_n(&mp[0][0],101*101,P(0,0));
    scanf("%d",&n);
    int a,b;
    For(i,n)
    {
      cin >> c[i];
      For(j,c[i])
      {
        cin >> a >> b;
        mp[i][j] = make_pair(a,b);
      }
      sort(&mp[i][0],&mp[i][0]+c[i],cmp);
    }
    //read data end.
    double ans = 0,tmp=0;
    int minb=0;
    for(int i = 0 ; i < n; ++i) //enumerate each device as the optimal
    {
      for(int j=0; j <c[i]; ++j)
      {
          //select current device as the optimal , then the other selected devices' brandth must be less than the minb
          minb = mp[i][j].first;  
          int k;
          int maxp = mp[i][j].second;

          for(k=0;k<n;++k)
          {
            if(k==i) continue; // the i-th devices has been included in solution
            int l=0; //max B/P. then the P must be the minimum one whose brandth is greater than the minb
            while(l<c[k] && mp[k][l].first < minb) ++l;
            if(l >= c[k]) break;
            maxp += mp[k][l].second;
          }
          if( k >= n && (tmp=static_cast<double>(minb)/maxp)>ans) ans=tmp;
      }
    }
    printf("%.3f\n",ans);
  }
  return 0;
}

*/

int dp[101][1001]; //the previous i devices with cost j
int b[101],p[101];
int c;

int t,n;
int main(void)
{
  scanf("%d",&t);
  while(t--)
  {
    fill_n(&dp[0][0],101*1001,-1);
    memset(b,0,sizeof(b));
    memset(p,0,sizeof(p));
    scanf("%d",&n);
    int maxb=0;
    For(i,n)
    {
      cin >> c;
      For(j,c)
      {
        cin >> b[j] >> p[j]; 
        maxb = max(maxb,b[i]);
      }
      //level by level to dp
      
      if(i == 0)
      {
        for(int k=0;k<c;++k)
            dp[i][b[k]] = p[k];
        continue;
      }
      
      for(int k=0;k<maxb;++k)
      {
        if(dp[i-1][k] != -1)
        {
          for(int l=0;l<n;++l)
          {
             int tb = min(k,b[l]);
             if(dp[i][tb] == -1)
             {
                dp[i][tb] = dp[i-1][k] + p[l];
             }
             else
             {
                dp[i][tb] = min(dp[i][tb],dp[i-1][k]+p[l]);
             }
          }
        }
      }
    }
    double ans=0,tmp=0;
    for(int i=0;i<maxb;++i)
    {
      if(dp[n-1][i] != -1)
      {
        if((tmp = static_cast<double>(i)/dp[n][i]) > ans)
            ans = static_cast<double>(i)/(dp[n][i]);
      }
    }
    printf("%.3f\n",ans);
  }
  return 0;
}


