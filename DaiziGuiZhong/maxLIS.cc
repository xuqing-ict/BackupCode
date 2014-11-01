/**
 * @file Candy.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
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
    TreeNode *left,*right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

void destory(TreeNode * &root)
{
    if(root == nullptr) return;
    destory(root->left);
    destory(root->right);
    root = nullptr;
    return;
}

void pre(TreeNode *root)
{
    if(root == nullptr) return;
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}

void in(TreeNode *root)
{
    if(root == nullptr) return;
    in(root->left);
    cout << root->val << " ";
    in(root->right);
}

struct fg
{
    int f;
    int g;
    fg(int _f=0,int _g=0):f(_f),g(_g){}
}; // f : include x, g: exclude x

void helper(TreeNode *root, unordered_map<TreeNode *,fg> & exist, int &cnt)
{
    if(root == nullptr || exist.find(root) != exist.end()) return;
    if(exist.find(root->left) == exist.end())
        helper(root->left,exist,cnt);
    if(exist.find(root->right) == exist.end())
        helper(root->right,exist,cnt);
    //contain x
    assert(exist.find(root->left) != exist.end());
    assert(exist.find(root->right) != exist.end());
    fg l = exist[root->left];
    fg r = exist[root->right];
    int f = root->val + l.g + r.g;
    int g = max(l.f,l.g) + max(r.f,r.g);
    if(f > g) ++cnt;
    exist.insert(make_pair(root,fg(f,g)));
}

int maxLIS(TreeNode *root)
{
    if(root == nullptr) return 0;
    unordered_map<TreeNode*,fg> exist;
    int cnt = 0; //record the size of LIS set
    exist.insert(make_pair(nullptr,fg(0,0)));
    helper(root,exist,cnt);
    int ret = max(exist[root].f, exist[root].g);
    cout << "size : " << cnt << endl;
    return ret;
}

int main(void)
{
    TreeNode *root =  new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->left->right->left = new TreeNode(70);
    root->left->right->right = new TreeNode(80);
    root->right->right = new TreeNode(60);
    pre(root); cout << endl;
    in(root); cout << endl;
    cout << "ans : " << maxLIS(root) << endl;
    destory(root);
    return 0 ;
}
