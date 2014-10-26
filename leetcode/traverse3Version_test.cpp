#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> InOrderTraverse2(TreeNode *root)
{
	vector<int> nodes;
	vector<int> temp;
	if(root == NULL) return nodes;
	temp = InOrderTraverse2(root->left);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	nodes.push_back(root->val);
	temp = InOrderTraverse2(root->right);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	return nodes;

}

vector<int> PreOrderTraverse2(TreeNode *root)
{
	vector<int> nodes;
	vector<int> temp;
	if(root == NULL) return nodes;
	nodes.push_back(root->val);
	temp = PreOrderTraverse2(root->left);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	temp = PreOrderTraverse2(root->right);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	return nodes;

}


vector<int> PostOrderTraverse2(TreeNode *root)
{
	vector<int> nodes;
	vector<int> temp;
	if(root == NULL) return nodes;
	temp = PostOrderTraverse2(root->left);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	temp = PostOrderTraverse2(root->right);
	for(vector<int>::size_type i = 0 ; i != temp.size() ; ++i)
		nodes.push_back(temp[i]);
	nodes.push_back(root->val);
	return nodes;

}

vector<int> PreOrderTraverse(TreeNode *root)
{
	vector<int> nodes;
	stack<TreeNode *> s;
	if(root == NULL) return nodes;
	TreeNode *temp = root;
	while(temp || !s.empty())
	{
		while(temp)
		{
			s.push(temp);//入栈之前就访问
			nodes.push_back(temp->val);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
	return nodes;
}

vector<int> InOrderTraverse(TreeNode *root)
{
	vector<int> nodes;
	if(root == NULL) return nodes;
	TreeNode *temp = root;
	stack<TreeNode *> s;

	while(temp || !s.empty())
	{
		while(temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		nodes.push_back(temp->val);
		s.pop();
		temp = temp->right;
	}
	return nodes;
}

vector<int> PostOrderTraverse(TreeNode *root)
{
	vector<int> nodes;
	if(root == NULL) return nodes;
	TreeNode *temp = root;
	TreeNode *pre = root; //记录前一次访问的节点
	stack<TreeNode *> s;
	while(temp || !s.empty())
	{
		while(temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		if (temp->right == NULL || pre == temp->right)
		{
			nodes.push_back(temp->val);
			pre = temp;
			s.pop();
			temp = NULL;//保证不重复访问
		}
		else
		{
			temp = temp->right;
		}
	}
	return nodes;
}



int main()
{
	vector<int> nodes;
	TreeNode *root = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	root->left = node2;
	root->right = node3;
	node5->right = node4;
	node3->left = node5;
	
	cout << "InOrder recursively..." << endl;
	nodes = InOrderTraverse2(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
	cout << "InOrder iterativelly..." << endl;
	nodes = InOrderTraverse(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
	cout << "PreOrder recursively..." << endl;
	nodes = PreOrderTraverse2(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
	cout << "PreOrder iterativelly..." << endl;
	nodes = PreOrderTraverse(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
	cout << "PostOrder recursively..." << endl;
	nodes = PostOrderTraverse2(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
	cout << "PostOrder iterativelly..." << endl;
	nodes = PostOrderTraverse(root);
	for(vector<int>::size_type i = 0; i != nodes.size(); i++)
		cout << nodes[i] << " ";
	cout << endl;
}
