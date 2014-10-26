/**
 * @file TreeList.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-22
 */
#include <bits/stdc++.h>
#include<assert.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//inorder tranverse for build the double linked list
TreeNode *convert(TreeNode *root)
{
    cout << "convert ... " << endl;
    if(root == NULL) return NULL;
    stack<TreeNode *> s;
    TreeNode dummy(0), *head = &dummy;
    while(root || !s.empty())
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        head->right = root;
        root->left = head;
        head = head->right;
        root= root->right;
    }
    return dummy.right;
}

//recursive
TreeNode *convert2(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    TreeNode dummy(0),*head=&dummy;
    //convert left subtree
    if(root->left)
    {
        TreeNode *L = convert2(root->left);
        head->right = L;
        L->left = head;
        while(head->right) head = head->right;
    }
    //add root
    head->right = root;
    root->left = head;
    head = root;
    if(root->right)
    {
        TreeNode *R = convert2(root->right);
        head->right = R;
        R->left = head;
    }
    return dummy.right;

}
int main(void)
{
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node14 = new TreeNode(14);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node12 = new TreeNode(12);
    TreeNode *node16 = new TreeNode(16);
    node10->left = node6;
    node10->right = node14;
    node6->left = node4;
    node6->right = node8;
    node14->left = node12;
    node14->right = node16;
    node10 = convert2(node10);
    TreeNode *head = node10->right;

    while(head && head->right)
    {
        cout << head->left->val << " " << head->val  << " " << head->right->val << endl;
        head = head->right;
    }
    cout << endl;
    delete node10;
    delete node6;
    delete node14;
    delete node4;
    delete node8;
    delete node12;
    delete node16;
    return 0;
}

