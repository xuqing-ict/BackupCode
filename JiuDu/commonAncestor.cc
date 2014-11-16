//树中任意两个节点的最近公共祖先
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

bool GetNodePath(TreeNode *root, TreeNode *node, list<TreeNode *> &path)
{
    if(node == root)
    {
        path.push_back(root);  //对于一个node是另一个node的祖先的情况！！以及一个node是根节点的情况
        return true;
    }
    path.push_back(root);
    bool found = false;
    if(root->left)
        found = GetNodePath(root->left,node,path);
    //
    if(!found && root->right)
        found = GetNodePath(root->right,node,path);
    if(found == false)
    {
        path.pop_back();
    }
    return found;
}

TreeNode *getLastCommonNode(const list<TreeNode *> &list1, const list<TreeNode * > &list2)
{
    auto iter1 = list1.begin(), iter2 = list2.begin();
    TreeNode *ret = nullptr;
    while(iter1 != list1.end() && iter2 != list2.end())
    {
        if(*iter1 == *iter2)
        {
            ret = *iter1;
        }
        ++iter1;++iter2;
    }
    return ret;
}
TreeNode *getCommonAncester(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    if(root == nullptr || node1 == nullptr || node2 == nullptr) return nullptr;
    list<TreeNode *> path1,path2;
    bool found1 = GetNodePath(root,node1,path1);
    bool found2 = GetNodePath(root,node2,path2);
    //detect path1 and path2
    cout << "path1 : ";
    for(auto a: path1) cout << a->val << "\t";
    cout << endl;

    cout << "path2 :";
    for(auto a: path2) cout << a->val << "\t";
    cout << endl;
    if(found1 == false || found2 == false)
    {
        return nullptr;
    }
    TreeNode *ret = getLastCommonNode(path1, path2);
    return ret;
}

void destory(TreeNode * &root)
{
    if(root == nullptr) return;
    if(root->left) destory(root->left);
    if(root->right) destory(root->right);
    delete root;
    root = nullptr;
    return;
}

bool exist(TreeNode *root, TreeNode *node)
{
    if(root == nullptr) return true;
    if(root == node) return true;
    return exist(root->left,node) || exist(root->right,node);
}

TreeNode *getCommonAncesterInBST(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    if(root == nullptr || node1 == nullptr || node2 == nullptr) return nullptr;
    TreeNode *cur = root;
    while(cur != nullptr)
    {
        if(cur->val <= node1->val && cur->val >= node2->val)
        {
            if(exist(cur->left,node2) && exist(cur->right,node1))
            {
                return cur;
            }
        }
        else if(cur->val >= node1->val && cur->val <= node2->val)
        {
            if(exist(cur->left,node1) && exist(cur->right, node2))
            {
                return cur;
            }
        }
        else
        {
            if(cur->val < node1->val && cur->val < node2->val)
                return getCommonAncesterInBST(cur->right,node1,node2);
            else
                return getCommonAncesterInBST(cur->left, node1,node2);
        }
    }
    return nullptr;
}


int main(void)
{
    TreeNode *root0  = new TreeNode(0);
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);
    TreeNode *root6 = new TreeNode(6);

    TreeNode *root = root3;
    root3->left = root1;
    root3->right = root5;

    root1->left = root0;
    root1->right = root2;

    root5->left = root4;
    root5->right = root6;

    TreeNode *node1 = root4 , *node2 = root5;
    TreeNode *ret = getCommonAncester(root,node1,node2);
    if(ret) cout << node1->val << "\t" << node2->val << " common ancester : " << ret->val << endl;
    else cout << "no common ancester..." << endl;
    destory(root);

    return 0;
}
