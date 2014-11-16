#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(NULL),right(NULL){}
};

bool helper(TreeNode *root1, TreeNode *root2)
{
    if(root2 == nullptr) return true;
    if(root1 == nullptr) return false;
    if(root1->val != root2->val) return false;
    return helper(root1->left, root2->left) && helper(root1->right, root2->right);
}

bool isSubTree(TreeNode *root1, TreeNode *root2)
{
    bool ret = false;

    if(root1 && root2)
    {
        if(root1->val == root2->val)
        {
            ret = helper(root1,root2);
        }
        if(!ret)
            ret = isSubTree(root1->left, root2);
        if(!ret)
            ret = isSubTree(root1->right, root2);
    }
    return ret;
}
void destory(TreeNode * &root)
{
    if(root == nullptr) return;
    if(root->left) destory(root->left);
    if(root->right) destory(root->right);
    root = nullptr;
    return;
}
int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left =  new TreeNode(2);
    root1->right =  new TreeNode(3);

    TreeNode *root2 =  new TreeNode(1);
    root2->left =  new TreeNode(2);

    if(isSubTree(root1, root2))
        cout << "is subtree..." << endl;
    else
        cout <<"not subtree..." << endl;
    destory(root1);
    destory(root2);
    return 0;
}
