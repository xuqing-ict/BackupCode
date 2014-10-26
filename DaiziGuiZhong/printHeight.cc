/**
 * @file printHeight.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-25
 */

/*有一个棵树，不一定是二叉树，有n个节点，编号为0到n-1。有一个数组A，
 * 数组的索引为0到n-1，数组的值A[i]表示节点i的父节点的id，根节点的
 * 父节点id为-1。给定数组A，求得树的高度。*/

#include <bits/stdc++.h>
using namespace std;

int getHeight(const vector<int> &A, vector<int> &height, int idx)
{
    if(height[idx] != -1) //has computed
        return height[idx];

    if(A[idx] == -1) //root
    {
        height[idx] = 1;
    }
    else
    {
        height[idx] = 1 + getHeight(A,height,A[idx]);
    }
    return height[idx];

}

vector<int> printHeight(const vector<int> &A)
{
    const int n = A.size();
    if(n == 0) return vector<int>();
    vector<int> height(n,-1);
    int maxHeight = 0;

    for(int i=0;i<n;++i)
        if(height[i] == -1)
            maxHeight = max(maxHeight, getHeight(A,height,i));
        //height[i] = getHeight(A,height,i);
    return height;
}

int main(void)
{
    vector<int> parent = {3,3,3,-1,2};
    vector<int> height = printHeight(parent);
    for(auto a:height) cout << a << "\t";
    cout << endl;
    return 0;
}

