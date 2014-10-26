#include <iostream>
#include <stack> 
using namespace std;
 
struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void BSTiso(TreeNode *root)
{
	if(root == NULL) return ;
	swap(root->left, root->right);
	BSTiso(root->left);
	BSTiso(root->right);
}
//iterativelly
//preorder traverse
//
void BSTiso2(TreeNode *root)
{
    stack<TreeNode *> s;
    while(root || !s.empty())
    {
        while(root)
        {
            s.push(root);
            swap(root->left, root->right);
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
}

//pos_order_traverse
void BSTiso3(TreeNode *root)
{
    stack<TreeNode *> s;
	TreeNode *pre(NULL);
    while(root || !s.empty())
    {
		while(root)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		if(root->right == NULL || pre == root->right)
		{
			s.pop();
			pre = root;
			swap(root->left, root->right);
			root = NULL;
		}
		else
		{
			root = root->right;
		}
    }
    
}
void InOrderTraverse2(TreeNode *root)
{
	if( root == NULL ) return;
	InOrderTraverse2(root->left);
	cout << root->val << " ";
	InOrderTraverse2(root->right);
}

void PreOrderTraverse2(TreeNode *root)
{
	if( root == NULL ) return;
	cout << root->val << " ";
	PreOrderTraverse2(root->left);
	PreOrderTraverse2(root->right);

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

	node4->left = node3;
	
	cout << "InOrder = :";
	InOrderTraverse2(node6);
	cout << endl;

	cout << "PreOrder= :";
	PreOrderTraverse2(node6);
	cout << endl;

	BSTiso(node6);
	cout << "InOrder = :";
	InOrderTraverse2(node6);
	cout << endl;
	cout << "PreOrder = :";
	PreOrderTraverse2(node6);
	cout << endl;
    BSTiso2(node6);
	cout << "InOrder = :";
	InOrderTraverse2(node6);
	cout << endl;
	cout << "PreOrder = :";
	PreOrderTraverse2(node6);
	cout << endl;
	BSTiso3(node6);
	cout << "InOrder = :";
	InOrderTraverse2(node6);
	cout << endl;
	cout << "PreOrder = :";
	PreOrderTraverse2(node6);
	cout << endl;
	delete node6;
	delete node2;
	delete node8;
	delete node1;
	delete node4;
	delete node3;
}

