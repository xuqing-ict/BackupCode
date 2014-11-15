/**
 * @file pathTreeSum.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-15
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

void destory(TreeNode * &root)
{
    if(root == nullptr) return;
    destory(root->left);
    destory(root->right);
    root=nullptr;
}

void helper(TreeNode *root, const int sum, vector<int> &path, int cur_sum)
{
    if(root == nullptr) return;
    path.push_back(root->val);
    cur_sum += root->val;
    if(cur_sum == sum)
    {
        for(auto a:path) cout << a << " ";cout << endl;
    }
    helper(root->left,sum,path,cur_sum);
    helper(root->right,sum,path,cur_sum);
    path.pop_back();
}

void findSum(TreeNode *root, const int sum)
{
    if(root == nullptr)return;
    vector<int> path;
    helper(root,sum,path,0);
    return;
}


int main(void)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    const int sum = 4;
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(-1);
    
    findSum(root,sum);
    destory(root);
    return 0 ;
}
