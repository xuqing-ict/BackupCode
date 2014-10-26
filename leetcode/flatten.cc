#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode *helper(TreeNode *root)
    {
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right == nullptr) return root;
        
        TreeNode *L = helper(root->left);
        TreeNode *R = helper(root->right);
        
        //root->left = nullptr;
        root->right = L;
        L = root;
        while(L->right) L = L->right;
        L->right = R;
        return root;
    }
public:
    void flatten(TreeNode *root) {
        root = helper(root);
        while(root) {
            assert(root->left == nullptr);
            root = root->right;
        }
    }
};

int main(void)
{
    Solution o;
    TreeNode node1(1), node2(2);
    node1.right = &node2;
    o.flatten(&node1);
    return 0;
}
