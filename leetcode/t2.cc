
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};


//Morris Traverse + Store the min/max value
int maxDiffNode(TreeNode *root)
{
    if(root == nullptr) return 0;
    assert(root);
    int maxValNode = INT_MIN, minValNode = INT_MAX;
    while(root)
    {
        if(root->left == nullptr)
        {
            maxValNode = max(maxValNode,root->val);
            minValNode = min(minValNode,root->val);
            root = root->right;
        }
        else
        {
            TreeNode *tmp = root->left;
            while(tmp->right && tmp->right != root) tmp=tmp->right;
            if(tmp->right == nullptr)
            {
                tmp->right=root;
                root=root->left;
            }
            else
            {
                maxValNode = max(maxValNode,root->val);
                minValNode = min(minValNode,root->val);
                tmp->right = nullptr;
                root = root->right;
            }
        }
    }
    return abs(maxValNode-minValNode);
}


int main(void)
{
    cout << maxDiffNode(root) << endl;
    return 0;
}
