/**
 * @file binrarySeacrchTree.cc
 * @brief binary search tree
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-03
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right,*parent;
    TreeNode(int x):val(x),left(NULL),right(NULL),parent(NULL){}
};

void addNode(TreeNode * & root, int x)
{
  cout << "xq add "  <<  x << endl;
  TreeNode *node = new TreeNode(x);
  if(root == NULL) 
  {
      root = node;
      return;
  }
  TreeNode *temp =  root, *prev = NULL;
  while(temp)
  {
    prev =  temp;
    if(temp->val <= x) temp = temp->right;
    else if(temp->val > x) temp =  temp->left;
  }
  if(prev->val >= x)
  {
    prev->left = node;
    node->parent = prev;
  }
  else
  {
    prev->right = node;
    node->parent = prev;
  }
}

TreeNode *buildTree(const vector<int> &data)
{
    if(data.empty()) return NULL;
    TreeNode *root = NULL;
    for(int i =0  ; i < data.size(); ++i)
    {
      addNode(root, data[i]);
    }
    return root;
}
void destoryTree(TreeNode * &root)
{
    if(root == NULL) return;
    destoryTree(root->left);
    destoryTree(root->right);
    delete root;
    root = NULL;
}

void InOrderTraverse(TreeNode *root)
{
    if(root == NULL) return;
    stack<TreeNode *> s;
    while(root || !s.empty())
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        cout << root->val << "\t";
        s.pop();
        root = root->right;
    }
}

void RecursiceInOrderTraverse(TreeNode *root)
{
    if(root == NULL) return;
    RecursiceInOrderTraverse(root->left);
    cout << root->val << "\t";
    RecursiceInOrderTraverse(root->right);
}

TreeNode *min(TreeNode *root)
{
    if(root == NULL) return NULL;
    while(root->left)
    {
        root= root->left;
    }
    return root;
}
//find the next node of cur and return
TreeNode *next(TreeNode *cur)
{
  assert(cur != NULL);
  if(cur->right)
  {
    return min(cur->right);
  }
  else
  {
    TreeNode *parent = cur->parent;
    while(parent && parent->right == cur)
    {
        cur = parent;
        parent = cur->parent;
    }
    return parent;
  }
}

int main()
{
  vector<int> data = {4,5,6,2,3};
  TreeNode *root =  buildTree(data);

  //InOrderTraverse(root);
  RecursiceInOrderTraverse(root);
  cout << endl;
  cout << next(root)->val << endl;
  destoryTree(root);
}
