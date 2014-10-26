//在二元树中找出和为某一值的所有路径，并打印出这些路径
#include<iostream> 
#include<vector>
#include<queue>

using namespace std;

struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

int sum = 0;

void add_node(BSTreeNode * &parent,int value1, int value2,queue<BSTreeNode *> &nodeQueue)
{
	if (value1 != -1)
	{
	
		BSTreeNode *p = new BSTreeNode;
		p->m_nValue = value1;
		p->m_pLeft = NULL;
		p->m_pRight = NULL;
		parent->m_pLeft = p;
		nodeQueue.push(p);
	}
	if (value2 != -1)
	{
		BSTreeNode *pr = new BSTreeNode;
		pr->m_nValue = value2;
		pr->m_pLeft = NULL;
		pr->m_pRight = NULL;
		parent->m_pRight = pr;
		nodeQueue.push(pr);
	}

}
void build_tree(BSTreeNode * &tree, vector<int> nodeList)
{
	cout << "start build tree..." << endl;
	cout << "nodeList.size() = " << nodeList.size() << endl;

	int value1 = -1, value2 = -1;
	int value;
	queue<BSTreeNode*> nodeQueue;
	if (0 == nodeList.size())
	{
		cout << "nodeList is empty..." << endl;
	}

	vector<int>::size_type it = 0 ; // record pos in nodeList
	
	value = nodeList[it++];
	cout << "add value " << value << endl;

	BSTreeNode *p1 = new BSTreeNode;
	if (NULL == p1)
	{
		cerr << "new error!!!" << endl;
	}
	p1->m_nValue = value;
	p1->m_pLeft = NULL;
	p1->m_pRight = NULL;
	tree = p1;
	nodeQueue.push(tree);

	if (it == nodeList.size())
	{
		cout << "only has a root" << endl;
		return;
	}
	while ( !( nodeQueue.empty() ) )
	{
		value1 = -1;
		value2 = -1;
		//取出队首元素
		cout << "queue is not empty..." << endl;
		BSTreeNode *&parent = nodeQueue.front();
		nodeQueue.pop();
		
		if (it == nodeList.size())
		{
			cout << "node is used up..." << endl;
			return; 
		}
		value1 = nodeList[it++];
		if (it == nodeList.size())
		{
			cout << "node is used up..." << endl;
			return; 
		}

		value2 = nodeList[it++];
		add_node(parent,value1,value2,nodeQueue);
	}
}

vector<int> path;

void first_root_traverse(BSTreeNode *tree,int target)
{
	if (NULL == tree)
	{
		return;
	}
	cout << tree->m_nValue << endl;
	sum += tree->m_nValue;
	path.push_back(tree->m_nValue);
	first_root_traverse(tree->m_pLeft,target);
	first_root_traverse(tree->m_pRight,target);
	if (tree->m_pLeft == 0 && tree->m_pRight == 0)
	{
		cout << "sum = " << sum << endl;
		if (sum == target)
		{
			cout << " sum == target " << endl;
			for(vector<int>::size_type i = 0; i != path.size() ; ++i)
			{
				cout  << "path = " << path[i] << " ";
			}
			cout << endl;
		}
	}
	sum -= tree->m_nValue;
	path.pop_back();
	
}

int main()
{	
	vector<int> nodeList;
	BSTreeNode *tree = NULL;

	int number;
	int target;

	cout << "input tree node,return <ctrl + D>..." << endl;
	cin >> target;

	while(cin >> number)
	{
		nodeList.push_back(number);
	}
	
	cout << "target = "  << target << endl;
	
	build_tree(tree,nodeList);
	cout << "tree first traverse" << endl;
	first_root_traverse(tree,target);
	return 0;
}
