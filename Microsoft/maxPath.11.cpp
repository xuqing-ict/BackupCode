//maxPath与depth没有子结构之间的关系
#include<iostream>
#include<cstdlib>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


int depth(TreeNode *root)
{
	if(root == NULL)return 0;
	return 1 + max(depth(root->left) , depth(root->right));
}



int maxPath(TreeNode *root)
{
	if(root == NULL) return 0;
	return depth(root->left) + depth(root->right);
}


int main()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);
	
	node1->left = node2;
	node1->right = node4;
//	node2->right = node3;
//	node2->left = node7;
//	node4->left = node5;
//	node4->right = node6;

	cout << "max path = " << maxPath(node1) << endl;

	return EXIT_SUCCESS;
}
