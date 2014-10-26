/**
 * @file Maze.cc
 * @brief Maze
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-13
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

void bfs(vector<string> &maze, const int start_x, const int start_y,const int end_x, const int end_y, vector<vector<int> > &dis)
{
  queue<pair<int,int> > q;
  pair<int,int> s = make_pair(start_x, start_y);
  q.push(s);
  
  dis[start_x][start_y]= 0;
  const int m = maze.size();
  const int n = maze[0].size();

  while(!q.empty())
  {
    s = q.front();q.pop();
    int x = s.first, y=s.second;
    for(int i = 0;i<4;++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= 0 && nx< m && ny >= 0 && ny < n)
      {
        if(maze[nx][ny] == '#' || dis[nx][ny] != MAX)continue;
        q.push(make_pair(nx,ny));
        dis[nx][ny] = dis[x][y] +1;
        if(nx == end_x && ny == end_y) break;
      }
    }
  }
}
int main()
{
  vector<string> maze;
  int n ;
  cin >> n;
  string str;
  for(int i = 0 ;  i< n;++i)
  {
    cin >> str;
    maze.push_back(str);
  }
  cout << maze.size() << " " << maze[0].size() << endl;

  int start_x = -1, start_y=-1, end_x = -1, end_y = -1;
  bool start = false, end = false;
  for(int i = 0 ;  i < maze.size() ; ++i)
  {
    for(int j = 0 ;  j < maze[i].size(); ++j)
    {
      if(maze[i][j] == 'S')
      {
        if(start) throw runtime_error("Input illegal!!!");
        start_x = i ; start_y = j;
      }
      if(maze[i][j] == 'G')
      {
        if(end) throw runtime_error("Input illegal!!!");
        end_x= i ; end_y = j;
      }
    }
  }
  cout << start_x << " " << start_y << endl;
  cout << end_x << " " << end_y << endl;
  vector<vector<int> > dis(maze.size(), vector<int> (maze[0].size(), MAX));
  bfs(maze,start_x,start_y,end_x, end_y,dis);
  cout << "min dis : " << dis[end_x][end_y] << endl;
  return 0;
}
