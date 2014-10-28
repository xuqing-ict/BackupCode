/**
 * @file 3069.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-27
 */

//Greedy
//给定直线上的n个点，每个点的坐标为xi，现在挑选某些点，给他们加上标记，对于每一个点来说，需要该点的周围的r氛围内必须有一个被标记的点，那么问至少要标记的点的个数

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<(n);++i)

int pos[1001];
int r,n;

int minLabel()
{
  if(n <= 1) return n;
  sort(pos,pos+n);
  int idx = 0; // record current rightmost position
  int left = pos[0];
  int ans=0;
  while(idx < n)
  {
      left = pos[idx++]; //from next postion to compare
      while(idx < n && left + r >= pos[idx]) ++idx;
      left = pos[idx-1]; //labal here
      while(idx < n && left + r >= pos[idx]) ++idx;
      ++ans;
  }
  return ans;
}

int main(void)
{
  while(scanf("%d %d",&r,&n)!=EOF)
  {
    if( r == -1 && n == -1) break;
    fill_n(pos,1001,0);
    For(i,n)
        cin >> pos[i];
    cout << minLabel() << endl;
  }
  return 0;
}

