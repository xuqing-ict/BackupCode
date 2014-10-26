#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void levelPrint(TreeNode *root)
{
	if(root == NULL) return;
	queue<TreeNode *> q;
	TreeNode *temp(NULL);
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		
	}
	cout << endl;
}

void inTraverse(TreeNode *root)
{
  cout << "In order..." << endl;
  while(root != nullptr)
  {
    if(root->left == nullptr)
    {
      cout << root->val << "\t";
      root = root->right;
    }
    else
    {
      TreeNode *tmp = root->left;
      while(tmp->right != nullptr && tmp->right != root)
        tmp = tmp->right;
      if(tmp->right == nullptr)
      {
          tmp->right = root;
          root = root->left;
      }
      else if(tmp->right == root)
      {
          cout << root->val << "\t";
          tmp->right = nullptr;
          root = root->right;
      }
    }
  }
}

{ 
  cout << "pos order..." << endl;
  while(root != nullptr)
  {

  }
}
int main()
{
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node8 = new TreeNode(8);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node3 = new TreeNode(3);
	node6->left = node2;
	node6->right = node8;

	node2->left = node1;
	node2->right = node4;

	node8->left = node3;
	levelPrint(node6);
    inTraverse(node6);
    cout << endl;
	delete node6;
	delete node2;
	delete node8;
	delete node1;
	delete node4;
	delete node3;
}
