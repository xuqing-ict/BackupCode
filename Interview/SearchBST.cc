/**
 * @file SearchBST.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-21
 */

//在二叉查找树中找一个与target最接近的节点
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int FindNearestNumberInBST(TreeNode *root, const int target)
{
    assert(root != nullptr);
    int minInterval = INT_MAX, ret=-1;
    while(root)
    {
        int dev=root->val-target;
        if ( abs(dev) < minInterval) { minInterval = abs(dev); ret=root->val;}

        if(dev == 0) {break;}
        else if(dev<0) root=root->right;
        else  root=root->left;
    }
        /*
        if(root->val == target) 
        {
            ret=root->val;
            minInterval = 0;
            break;
        }
        else if(root->val > target) 
        {
            if(abs(root->val-target) < minInterval)
            {
                minInterval = abs(root->val-target);
                ret=root->val;
            }
            root=root->left;
        }
        else 
        {
            if(abs(root->val-target) < minInterval)
            {
                minInterval = abs(root->val-target);
                ret=root->val;
            }
            root=root->right;
        }
        */
    //}
    cout << minInterval << endl;
    return ret;
}

int main(void)
{
    TreeNode *root = new TreeNode(6);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node10 = new TreeNode(10);
    root->left=node3;root->right=node9;
    node3->left=node2;node3->right=node4;
    node9->left=node8,node9->right=node10;
    int target=7;
    cout << FindNearestNumberInBST(root,target) << endl;
    delete root;
    return 0;
}
