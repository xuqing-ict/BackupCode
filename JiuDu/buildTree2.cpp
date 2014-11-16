#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(NULL),right(NULL){}
};

TreeNode *helper(int *preBeg, int *preEnd, int *inBeg, int *inEnd)
{
    int rootVal = *preBeg;
    TreeNode *root =  new TreeNode(rootVal);

    if(preBeg == preEnd)
    {
        if(inBeg == inEnd && *preBeg == *inEnd)
            return root;
        else
        {
            cout << "No" << endl;
            throw runtime_error("Illegal input!!!");
            exit(1);
        }
    }

    //find the split node
    int *splitNode=inBeg;
    while(splitNode != inEnd && *splitNode != rootVal)
    {
        ++splitNode;
    }
    if(splitNode == inEnd && *splitNode != rootVal)
    {
        cout << "No" << endl;
        throw runtime_error("Illegal input!!!");
        exit(1);
    }
    int leftLen = splitNode - inBeg;
    int *leftPreOrderEnd = preBeg + leftLen;
    if(leftLen > 0)
    {
        root->left = helper(preBeg+1, leftPreOrderEnd, inBeg, splitNode-1);
    }
    if(leftLen < preEnd - preBeg)
    {
        root->right = helper(leftPreOrderEnd+1,preEnd, splitNode+1,inEnd);
    }
    return root;
}

TreeNode * buildTree(int *preOrder, int *inOrder, int length)
{
    if(preOrder == NULL || inOrder == NULL || length <= 0)
    {
        return NULL;
    }
    return helper(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

void preOrderF(TreeNode *root)
{
    if(root == NULL) return;
    cout << root->val << "\t";
    preOrderF(root->left);
    preOrderF(root->right);
}
void inOrderF(TreeNode *root)
{
    if(root == NULL) return;
    inOrderF(root->left);
    cout << root->val << "\t";
    inOrderF(root->right);
}

void posOrder(TreeNode *root)
{
    if(root == NULL) return;
    posOrder(root->left);
    posOrder(root->right);
    cout << root->val << "\t";
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int *preOrder =  new int[n];
        int *inOrder = new int[n];
        for(int i =0  ; i<n;++i)
            scanf("%d",&preOrder[i]);
        for(int i =0  ; i<n;++i)
            scanf("%d",&inOrder[i]);

        bool illegal = false;
        TreeNode *root = buildTree(preOrder, inOrder, n);
        /*preOrderF(root);
        cout << endl;
        inOrderF(root);
        cout << endl;
        */
        posOrder(root);
        cout << endl;
    }
    return 0;
}
