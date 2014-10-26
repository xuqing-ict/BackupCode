//层次遍历并且按层次输出
//
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > levelOrder(TreeNode *root) {
		cout << "levelOrder..." << endl;
        queue<TreeNode *> myQueue;
        vector<vector<int> > allLevels;
        vector<int> level;
        if(root == NULL)return allLevels;
        
        myQueue.push(root);
        myQueue.push((TreeNode *)NULL);
		
        while(!(myQueue.empty()))
        {
			TreeNode *temp = (TreeNode *)myQueue.front();
            myQueue.pop();

            if(temp == (TreeNode *)NULL)
            {
				cout << "here 1" << endl;
				if (!myQueue.empty())
					myQueue.push((TreeNode *)NULL);
                allLevels.push_back(level);
                level.clear();
                continue;
            }
            else
            {
				cout << "front->val = " << temp->val << endl;
				cout << "here 2" << endl;
                if(temp->left)myQueue.push(temp->left);
                if(temp->right)myQueue.push(temp->right);
				cout << "here 2" << endl;
                level.push_back(temp->val);
				cout << "here 2" << endl;
            }
        }
        return allLevels;
}
vector<vector<int> > levelOrder2(TreeNode *root) {
        queue<TreeNode *> queue1;
        queue<TreeNode *> queue2;
        vector<vector<int> > allLevels;
        vector<int> level;
        if(root == NULL) return allLevels;
        queue1.push(root);
        while(!queue1.empty())
        {
            TreeNode *temp = queue1.front();
            queue1.pop();
            if(temp->left)queue2.push(temp->left);
            if(temp->right)queue2.push(temp->right);
            level.push_back(temp->val);
            if(queue1.empty())
            {
                //queue1 = queue2;
				//queue2.clear();
				swap(queue1,queue2);
                allLevels.push_back(level);
                level.clear();
            }
        }
        return allLevels;
}


vector<int> preOrderTraversal(TreeNode *root)
{
	vector<int> nodes;

	if(root == NULL) return nodes;
	stack<TreeNode *> myStack;
	//myStack.push(root);
	TreeNode *temp = root;

	//temp != NULL主要是用来处理root节点时，栈还是空的情况。
	//或者是某个节点的右孩子为空时，那么直接跳出内部的while循环，直接取它的父节点来处理。
	while(temp != NULL ||!myStack.empty())
	{
		while(temp)
		{
			nodes.push_back(temp->val);
			myStack.push(temp);
			temp = temp->left;
		}
		temp = myStack.top();
		myStack.pop();
		temp = temp->right;
	}
	return nodes;
}


int main()
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(6);
	TreeNode *t7 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;
	vector<vector<int> > levels;
	levels = levelOrder(t1);
	cout << "levels size = " << levels.size() << endl;
	for(int i = 0 ; i < levels.size(); ++i)
	{
		for(int j = 0; j < levels[i].size() ;++j)
			cout << levels[i][j] << " ";
		cout << endl;
	}
levels = levelOrder2(t1);
	cout << "levels size = " << levels.size() << endl;
	for(int i = 0 ; i < levels.size(); ++i)
	{
		for(int j = 0; j < levels[i].size() ;++j)
			cout << levels[i][j] << " ";
		cout << endl;
	}
	vector<int> nodes;
	nodes = preOrderTraversal(t1);
	cout << "nodes = ";
	for(int j = 0; j < nodes.size() ;++j)
		cout << nodes[j] << " ";
	cout << endl;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;
    delete t7;
    
}
