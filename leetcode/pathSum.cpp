//判断在一棵二叉树中是否存在一条从根节点到叶子节点的和为sum的路径。

#include <iostream>
using namespace std;

const int sum = 22;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
bool hasPathSum(TreeNode *root, int sum) {
	if (root == NULL) return false;
	cout << "root = " << root->val << " " << "sum = " << sum << endl;
	if(root->left == NULL &&  root->right == NULL && sum == root->val) return true;
	if( ((root->left) && (hasPathSum(root->left,sum-root->val))) || ((root->right) && (hasPathSum(root->right,sum-root->val))))
		return true;
	return false;
}

int main()
{

	TreeNode *root = new TreeNode(5);
	TreeNode *node1 = new TreeNode(4);
	TreeNode *node2 = new TreeNode(8);
	root->left = node1;
	root->right = node2;

	TreeNode *node3 = new TreeNode(11);
	node1->left = node3;
	TreeNode *node4 = new TreeNode(13);
	TreeNode *node5 = new TreeNode(4);
	node2->left = node4;
	node2->right = node5;
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(2);
	node3->left = node6;
	node3->right = node7;
	TreeNode *node8 = new TreeNode(1);
	node5->right = node8;
	
	
	if(hasPathSum(root,sum))
		cout << "YES!!" << endl;
	else
		cout << "NO!!!" << endl;	
	
	delete root;
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
	delete node8;

}





