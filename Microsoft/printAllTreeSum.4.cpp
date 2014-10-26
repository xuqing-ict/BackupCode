/*
 * 4.在二元树中找出和为某一值的所有路径(树)
	题目:输入一个整数和一棵二元树。
	从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
	打印出和与输入整数相等的所有路径。
	例如 输入整数 22 和如下二元树
	10
	/ \
	5 12
   / \
   4  7
	则打印出两条路径:10, 12 和 10, 5, 7。

*
* */

#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

void printPath(vector<int> & path)
{
//	cout << root->val << endl;
//	path.push_back(root->val);
	copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return;
}
/*
 * treeSum如果传入的是path形参 并非它的引用，那么空间复杂度可能会是指数级别的。
 * 如果传入的是引用，那么必须考虑在每一个节点的左孩子和右孩子考虑完毕之后，弹出该节点，
 * 因为如果左右孩子中有合适的路径出现的话，那么该路径已经被输出，因此必须弹出该节点。
*/
void treeSum(TreeNode *root, int sum, vector<int> &path)
{
	
	if(root == NULL)return;
	path.push_back(root->val);
	if(root->left == NULL && root->right==NULL && root->val == sum)
		printPath(path);
	treeSum(root->left, sum-root->val, path);
	treeSum(root->right, sum-root->val, path);
	path.pop_back();
}


int main()
{
	TreeNode *node10 = new TreeNode(10);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node12 = new TreeNode(12);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node6 = new TreeNode(6);
	node10->left = node5;
	node10->right = node12;
	node5->left = node4;
	node5->right = node7;
	node12->left = node6;

	TreeNode *root= node10;
	int sum = 22;
	vector<int> path;
	treeSum(node10,sum, path);
	delete node10;
	delete node5;
	delete node12;
	delete node4;
	delete node7;
	delete node6;

	return 0;
}
