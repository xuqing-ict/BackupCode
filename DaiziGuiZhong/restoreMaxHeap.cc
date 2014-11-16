//已知一个最大堆的中序遍历序里，要求恢复该最大堆。
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

void preTraverse(TreeNode *root)
{
    if(root == nullptr) return;
    cout << root->val << " ";
    preTraverse(root->left);
    preTraverse(root->right);
}
void inTraverse(TreeNode *root)
{
    if(root == nullptr) return;
    inTraverse(root->left);
    cout << root->val << " ";
    inTraverse(root->right);
}

void print(TreeNode *root)
{
     cout << "pre : " ;
    preTraverse(root);
    cout <<endl;
    cout << "In  : ";
    inTraverse(root);
    cout << endl;
}
TreeNode* buildMaxHeap(const vector<int> &A)
{
    const int n = A.size();
    if(n == 0) return nullptr;
    TreeNode *root = nullptr;
    stack<TreeNode *> s;
    bool ins = false;
    TreeNode *ptr = nullptr;
    for(int i=0;i<n;++i)
    {
        ptr = nullptr;
        ins = false;
        TreeNode *now = new TreeNode(A[i]);

        while(!s.empty())
        {
            ptr = s.top();
            if(ptr->val > A[i])
            {
                now->left = ptr->right;
                ptr->right = now;
                s.push(now);
                ins = true;
                break;
            }
            s.pop();
        }
        if(ins) continue; //add node end....
        now->left = ptr;
        s.push(now);
        root = now;
    }
    return root;
}
int main(void)
{
    const vector<int> A = {6,8,1,9,5,7,3};
    TreeNode *root = buildMaxHeap(A);
    print(root);
    return 0;
}
