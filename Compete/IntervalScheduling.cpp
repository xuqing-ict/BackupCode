// Last Update:2014-06-13 16:03:40
/**
 * @file IntervalScheduling.cpp
 * @brief interval scheduling for selecting more jobs
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-13
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &lhs, const pair<int,int> &rhs)
{
  return lhs.second < rhs.second;
}
int scheduling(vector<int> start, vector<int> &end)
{
  //最先结束的先选择，贪心
  assert(start.size() == end.size());
  vector<pair<int,int> > schedules;
  schedules.resize(start.size());
  for(int i=0;i<start.size();++i)
    schedules[i] = make_pair(start[i], end[i]);
  sort(schedules.begin(), schedules.end(), compare);
  for(int i=0;i<schedules.size();++i)
    cout << schedules[i].first << " " << schedules[i].second << endl;
  int ret=0, prev=0;
  for(int i = 0 ; i < schedules.size(); ++i)
  {
    if(schedules[i].first > prev)
    {
      ret++;
      prev= schedules[i].second;
    }
  }
  return ret;
}
int main()
{
  vector<int> start = {1,2,4,6,8};
  vector<int> end = {3,5,7,9,10};
  cout << scheduling(start,end) << endl;
  return 0;
}

