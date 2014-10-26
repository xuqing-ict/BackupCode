/**
 * @file maxRectangular.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-10
 */
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
#include <bits/stdc++.h>
using namespace std;

int maxRecArea( vector<int> &height)
{
    const int n =  height.size();
    height.push_back(0);
    stack<int> s;
    int ret = 0;
    for(int i=0;i<n+1;++i)
    {
        while(!s.empty() && height[s.top()] > height[i])
        {
            int h = height[s.top()];
            s.pop();
            ret = max(ret,(s.empty())?(h*i):(h*(i-s.top()-1)));
        }
        s.push(i);
    }
    height.pop_back();
    return ret;
}


int maximalRectangle(vector<vector<char> > &matrix) {
    const int m = matrix.size();
    if(m == 0) return 0;
    const int n = matrix[0].size();
    vector<int> tmp(n,0);
    int ret=0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(matrix[i][j] == '0') tmp[j]  = 0;
            else tmp[j] += 1;
        }
        ret = max(ret,maxRecArea(tmp));
    }
    return ret;
}

int main(void)
{
    vector<vector<char> > A = {{'1'}};
    cout << maximalRectangle(A) << endl;
    return 0;
}
