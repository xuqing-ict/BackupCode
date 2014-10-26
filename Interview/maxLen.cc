/**
 * @file maxLen.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-11
 */

#include <bits/stdc++.h>
using namespace std;

int height[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int startLen(const vector<vector<int> > &A, const int x, const int y)
{
    if(height[x][y] > 0) return height[x][y];
    int ret=1;
    const int m = A.size(), n = A[0].size();

    for(int i =0;i<4;++i)
    {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];
        if(cur_x >= 0 && cur_x < m && cur_y >= 0 && cur_y < n)
        {
            if(A[cur_x][cur_y] < A[x][y])
            {
                int cur = startLen(A, cur_x,cur_y) + 1;
                if(cur > ret) ret = cur;
            }
        }
    }
    return ret;
}
int maxLen(const vector<vector<int> > A)
{
    int maxRet = 0;
    const int m = A.size(), n = A[0].size();
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            height[i][j] = startLen(A,i,j);
            if(maxRet < height[i][j])
                maxRet = height[i][j];
        }
    }
    return maxRet;
}

int main(void)
{
    fill_n(&height[0][0], 101*101,-1);
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        vector<vector<int> > A(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &A[i][j]);
            }
        }
        cout << maxLen(A) << endl;
    }
    return 0;
}
