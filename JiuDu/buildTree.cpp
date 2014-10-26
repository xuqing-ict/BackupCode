
/*Input:
  样例输入：
  8
  1 2 4 7 3 5 6 8
  4 7 2 1 5 3 8 6
  8
  1 2 4 7 3 5 6 8
  4 1 2 7 5 3 8 6
  样例输出：
  7 4 2 5 8 6 3 1
  No
  */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val),left(NULL),right(NULL){}
};

TreeNode* buildTree(const vector<int> &pre,size_t preS, size_t preT, const vector<int> &In, size_t inS, size_t inT, bool & illegal)
{
    //cout << preS << "\t" << preT << "\t" << inS << "\t" << inT << endl;
    assert(preT-preS == inT-inS);
    if(preT < preS || illegal == true) return NULL;
    if(preT == preS)
    {
        TreeNode *node =  new TreeNode(pre[preS]);
        return node;
    }
    int pivot = pre[preS];
    int temp = inS;

    while(temp <= inT && In[temp] != pivot) ++temp;
    unordered_set<int> exist;
    for(int i=inS;i<=temp;++i)
        exist.insert(In[i]);
    for(int i=preS;i<preS+temp-inS+1;++i)
    {
        if(exist.find(pre[i]) == exist.end())
        {
            illegal = true;
            return NULL;
        }
    }
    TreeNode *root = new TreeNode(pivot);
    root->left = buildTree(pre,preS+1, preS+temp-inS,In,inS, temp-1,illegal);
    root->right = buildTree(pre,preS+1+temp-inS,preT,In, temp+1, inT,illegal);
    return root;
}

void PosOrderTraverse(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *prev = NULL;
    while(!s.empty()||root)
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == prev || root->right == NULL)
        {
            s.pop();
            cout << root->val << "\t";
            prev = root;
            root = NULL;
        }
        else
        {
            root = root->right;
        }
    }
}
ostream_iterator<int> out(cout,"\t");

void destory(TreeNode * &root)
{
    if(root == NULL) return ;
    destory(root->left);
    destory(root->right);
    delete root;
    root = NULL;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        vector<int> preOrder(n,0);
        vector<int> InOrder(n,0);
        for(int i =0  ; i<n;++i)
            scanf("%d",&preOrder[i]);
        for(int i =0  ; i<n;++i)
            scanf("%d",&InOrder[i]);
        copy(preOrder.begin(), preOrder.end(), out);
        cout << endl;
        copy(InOrder.begin(), InOrder.end(), out);
        cout << endl;

        bool illegal = false;
        TreeNode *root = buildTree(preOrder,0,n-1, InOrder,0,n-1,illegal);
        if (illegal == false)
        {
            PosOrderTraverse(root);
            cout << endl;
        }
        else
        {
            assert(root == NULL);
            cout << "No" << endl;
        }
        destory(root);
    }
    return 0;
}
