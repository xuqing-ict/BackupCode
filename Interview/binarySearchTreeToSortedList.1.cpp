#include <bits/stdc++.h>
#include<assert.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode *convert(TreeNode *root)
{
	cout << "convert ... " << endl;
	if(root == NULL) return NULL;
	stack<TreeNode *> s;
	TreeNode *temp = root;
	TreeNode *head = NULL;
	TreeNode *pre = NULL;
	while(temp || !s.empty())
	{
		while(temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		if(head == NULL)
		{
			head = temp;
			head->left = NULL;
			pre = head;
			temp = temp->right;
			continue;
		}
		if(pre)
		{
			pre->right = temp;
			temp->left = pre;
			pre = temp;
			temp = temp->right;
		}
	}
	return head;
}

//insert node
void insert(TreeNode * &root, int target)
{
	TreeNode *node = new TreeNode(target);
	if( root == NULL ) 
	{
		root = node;
		return;
	}
	if ( target == root->val )
	{
		cout << target << " exists ..." << endl;
	}
	else if (target < root->val)
	{
		insert(root->left, target);
	}
	else
	{
		insert(root->right , target);
	}
}

//find min element
TreeNode *findMin(TreeNode *root)
{
	if( root == NULL) return NULL;
	if ( root->left == NULL ) return root;
	else	return findMin( root->left );
}


//find max element
TreeNode *findMax(TreeNode *root)
{
	if( root == NULL ) return NULL;
	if( root->right == NULL) return root;
	else return findMax(root->right);
}

TreeNode * convertArrayToBST(int data[], int len)
{
	if(len == 0) return NULL;
	TreeNode *root = NULL;
	for(int i = 0 ; i < len ; ++i )
	{
		insert(root, data[i]);
	}
	return root;
}

//findPtr 必须传引用，否则会出错(传值 VS 传址)
bool search(TreeNode *root, int target , TreeNode * & findPtr)
{
	if(root == NULL){return false;}
	cout << "search..." << root->val << endl; 
	TreeNode *temp = root;
	if(target == temp->val)
	{
		findPtr = temp;
		cout << "find " << findPtr->val << endl;
		return true;
	}
	else if (target > temp->val)
	{
		return search(temp->right , target, findPtr );
	}
	else
	{
		return search(temp->left , target ,findPtr );
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
//constant space complexity
void InOrderTraverse(TreeNode *root)
{
	cout << "InOrderTraverse..." << endl;
	if( root == NULL ) return;
	TreeNode *pre = NULL;
	while(root)
	{
		if(root->left == NULL)
		{
			cout << root->val << " ";
			root = root->right;
			continue;
		}
		//if left not null
		for(pre = root->left; pre->right && pre->right != root ; pre = pre->right);
		//the first visiting time
		//for循环退出的条件是pre->rigth == NULL或者是pre->right == root.
		//分别考虑for循环退出的情况。
		if(pre->right == NULL)
		{
			pre->right = root;
			root = root->left;
		}
		//the second visiting time
		//说明当前节点的左子树已经访问过了
		else
		{
			cout << root->val << " ";
			root = root->right;
			pre->right = NULL;
		}
	}
}
/*
//recursivelly
TreeNode *convert2(TreeNode *root)
{
	if(root == NULL) return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;

	TreeNode *head = NULL;
	TreeNode *tempL = NULL;
	TreeNode *tempR = NULL;
	TreeNode *temp = NULL;

	if(root->left)	
	{
		tempL = convert2(root->left);
		temp = tempL;
		assert(temp != NULL);
		while(temp->right) temp = temp->right;
	}
	
	if(tempL) 
	{
		head = tempL;
		root->left = temp;
		temp->right = root;
	}
	else 
	{
		head = root;
	}
	if(root->right)
	{
		tempR = convert2(root->right);
		assert(tempR);
	    root->right = tempR;
	    tempR->left = root;
	}

	return head;
}
*/
TreeNode *convert2(TreeNode *root)
{
    if(root==nullptr) return nullptr;
    TreeNode dummy(0);
    TreeNode *head=&dummy;
    if(root->left)
    {
        TreeNode *L = convert2(root->left);
        head->right= L;
        L->left=head;
        while(head->right) head = head->right;
    }
    head->right=root;
    root->left=head;
    head=root;
    if(root->right)
    {
      TreeNode *R = convert2(root->right);
      head->right=R;
      R->left=head;
    }
    return dummy.right;
  
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
	
	TreeNode *findPtr = NULL;
	
	InOrderTraverse(node6);
	cout << endl;
	InOrderTraverse2(node6);
	cout << endl;
	PreOrderTraverse2(node6);
	cout << endl;
	cout << "find min " << findMin(node6)->val << endl;
	cout << "find max " << findMax(node6)->val << endl;

	//add node 7
	if ( search(node6,7,findPtr))
		cout << findPtr->val << endl;
	else
	{
		insert(node6,7);
		cout << "not find.." << endl;
	}

	InOrderTraverse(node6);
	cout << "InOrderTraverse iterativelly..." << endl;
	InOrderTraverse2(node6);
	cout << endl;
	PreOrderTraverse2(node6);
	cout << endl;
	cout << "find min " << findMin(node6)->val << endl;
	cout << "find max " << findMax(node6)->val << endl;
	
	/*
	//convert to sorted list
	cout << "convert ... " << endl;
	TreeNode *head = convert(node6);
	cout << "head = " << head->val << endl;
	head = head->right;
	while(head && head->right)
	{
		cout << head->left->val << " " << head->val  << " " << head->right->val << endl;
		head = head->right;
	}
	cout << endl;
	cout << "convert ..." << endl;
	*/
	



	cout << "convert2 ..." << endl;
	//convert to sorted list
	TreeNode *head = convert2(node6);
	cout << "head = " << head->val << endl;
	head = head->right;

	while(head && head->right)
	{
		cout << head->left->val << " " << head->val  << " " << head->right->val << endl;
		head = head->right;
	}
	cout << endl;
	cout << "convert 2 ..." << endl;

	
	//build BST
	int data[] = {1,4,3,2};
	int len = sizeof(data)/sizeof(int);
	cout << "build BST..." << endl;
	TreeNode *root = convertArrayToBST(data, len);
	InOrderTraverse(root);
	cout << "InOrderTraverse iterativelly..." << endl;
	InOrderTraverse2(root);
	cout << "PreOrderTraverse..." << endl;
	PreOrderTraverse2(root);
	cout << endl;

	delete node6;
	delete node2;
	delete node8;
	delete node1;
	delete node4;
	delete node3;

	return 0;
}
