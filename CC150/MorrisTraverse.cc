/**
 * @file traverse.cc
 * @brief Constant Morris traverse 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-02
 */

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left, *right, *parent;
  TreeNode(int x):val(x),left(NULL),right(NULL), parent(NULL){}
};

void InOrderTraverse(TreeNode *root)
{
  cout << "In : " ;
  while(root)
  {
      if(root->left==nullptr)
      {
        cout << root->val << "\t";
        root=root->right;
      }
      else
      {
        TreeNode *tmp=root->left;
        while(tmp->right && tmp->right != root) tmp=tmp->right;
        if(tmp->right==nullptr)
        {
          tmp->right=root;
          root=root->left;
        }
        else
        {
          tmp->right=nullptr;
          cout << root->val << "\t";
          root=root->right;
        }
      }
  }
  cout << endl;
}


void preOrderTraverse(TreeNode *root)
{
  cout << "pre : ";
  while(root)
  {
    if(root->left==nullptr)
    {
      cout << root->val << "\t";
      root=root->right;
    }
    else
    {
      TreeNode *tmp=root->left;
      while(tmp->right && tmp->right!=root)tmp=tmp->right;
      if(tmp->right==nullptr)
      {
        cout << root->val << "\t";
        tmp->right=root;
        root=root->left;
      }
      else
      {
        root=root->right;
        tmp->right=nullptr;
      }
    }
  }
  cout << endl;
}

void reverse(TreeNode *from, TreeNode *to)
{
  if(from==to) return;
  TreeNode *head=nullptr,*next=nullptr;
  while(from)
  {
    next=from->right;
    from->right=head;
    head=from;
    from=next;
  }
}
void reverse_print(TreeNode *from, TreeNode *to)
{
    reverse(from,to);
    TreeNode *tmp=to;
    while(tmp)
    {
      cout << tmp->val << "\t";
      tmp=tmp->right;
    }
    reverse(to,from);
}

void posOrderTraverse(TreeNode *root)
{
  cout << "pos : ";
  TreeNode dummy(0);
  dummy.left=root;
  root=&dummy;

  while(root)
  {
    if(root->left==nullptr)
    {
      root=root->right;
    }
    else
    {
      TreeNode *tmp=root->left;
      while(tmp->right && tmp->right != root)tmp=tmp->right;
      if(tmp->right==nullptr)
      {
        tmp->right=root;
        root=root->left;
      }
      else
      {
        tmp->right=nullptr; //must be here!!!
        reverse_print(root->left,tmp); 
        root=root->right;
      }
    }
  }
  cout << endl;
}
int main()
{
  TreeNode node1(1), node2(2),node3(3), node4(4), node5(5),node6(6), node7(7),node8(8);
  /*node1.left = &node2;
  node1.right = &node3;
  node2.left = &node7;
  node7.right = &node8;

  node3.left = &node4;
  node3.right = &node5;
  node4.left = &node6;
  */
  TreeNode *root = &node1;
  preOrderTraverse(root);
  InOrderTraverse(root);
  posOrderTraverse(root);
}
