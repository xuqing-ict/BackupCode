#include<iostream>
#include<cstdlib>
#include<cassert>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right,*parent;
	TreeNode(int x):val(x),left(NULL),right(NULL),parent(NULL){}
};


TreeNode *posNodeInOrder(TreeNode *root, TreeNode *cur)
{
	TreeNode *temp(NULL);
	if(root == NULL || cur == NULL) return NULL;
	if (cur->right)
	{
		temp = cur->right;
		for(;temp && temp->left ; temp = temp->left);
		assert(temp != NULL && temp->left == NULL);
		return temp;
	}
	else
	{
		temp = cur;
		for(; temp && temp->parent && temp->parent->left != temp; temp = temp->parent);
		return temp->parent;
	}
}


int main()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	/*
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
*/
//	node1->left = node2;
	node1->right = node2;
	node2->parent = node1;

//	node2->parent = node1;
	node2->right = node3;
	node3->parent = node2;
/*
	node3->left = node4;
	node4->parent = node3;
	node4->right = node5;
	node5->parent = node4;
*/
	TreeNode *ret = posNodeInOrder(node1, node3);
	if(ret) 
	{	
		cout << "ret->val = " << ret->val << endl;
	}

	return EXIT_SUCCESS;
}


