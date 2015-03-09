/**
 * @file countNodeInTree.cc
 * @brief count node number of a complete binart tree
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left, *right;

};
int depth(TreeNode *root)
{
    if(root == nullptr) return 0;
    int depth = 0;
    while(root)
    {
        root = root->left;
        ++depth;
    }
    return depth;
}

int countNode(TreeNode *root)
{
    if(root == nullptr) return 0;
    int d1 = depth(root->left);
    int d2 = depth(root->right);
    int cnt = 0;
    return (d1 == d2) ? (1<<d1)+countNode(root->right):(1<<d2)+countNode(root->left);
}

int main(void)
{
    TreeNode *root = nullptr;
    cout << "number : " << countNode(root) << endl;
}
