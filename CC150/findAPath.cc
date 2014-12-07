/**
 * @file findAPath.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-19
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
bool helper(const vector<string> &grid, int cur_x, int cur_y, vector<vector<bool> > &illegal, vector<P> &path)
{
    if(illegal[cur_x][cur_y])
    {
        return false;
    }
    
}

vector<P> getPath(const vector<string> &grid)
{
    vector<P> path;
    const int m = grid.size();
    if (m == 0) return path;
    const int n = grid[0].size();
    vector<vector<bool> > visited(m,vector<bool>(n,false));
    helper(grid,m-1,n-1,visited,path);
    return path;
}
int main(void)
{
    vector<string> grid;
    int n;
    cin >> n;
    grid.resize(n);
    for(int i=0;i<n;++i)
        cin >> grid[i];
    vector<P> path = getPath(grid) ;
    for(auto a : path)
        cout << a.first << " " << a.second << endl;
    return 0;
}
