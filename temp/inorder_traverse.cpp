#include<iostream> 
#include<vector>
//当指针作为参数传递到函数时，函数只能修改指针指向的对象的值，不能修改指针本身的指向。（即指针自己的值）
//如果要修改指针的指向，需传入指针的引用或者地址。

using namespace std;

struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

BSTreeNode *pHead = NULL; // the head of list
BSTreeNode *pCurrent = NULL; // current process node

void inOrder_traverse(BSTreeNode *tree);

void addTreeNode(BSTreeNode * &tree, int value)
{
	cout << "add node " << value << endl;
	BSTreeNode *pNode = new BSTreeNode;
	if (NULL == pNode)
	{
		cout << "new error!!" << endl;
	}
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	cout << "new a new node" << pNode->m_nValue << endl;
	
	if ( NULL == tree)
	{
		tree = pNode;
		cout << "add node " << value << " " << tree << " " << pNode << endl;
		if (NULL == tree)
		{
			cout << "WHY TREE EMPTY!!!" << endl;
		}
		return;
	}
	else
	{

		BSTreeNode *p = tree;
		if (p->m_nValue > value)
		{
			addTreeNode(tree->m_pLeft,value);
		}
		else if (p->m_nValue < value)
		{
			addTreeNode(tree->m_pRight,value);
		}
		else
		{
			cout << "repeat node!!!" << endl;
		}
	}
	cout << "tree..." << endl;
	//inOrder_traverse(tree);
}
// build the tree, we should use the tree ** or tree reference as the paramater!!!!
void build_tree(vector<int> nodeList,BSTreeNode* &tree)
{
	cout << "begin build tree..." << endl;
	for(vector<int>::size_type it = 0; it != nodeList.size(); ++it)
	{
		addTreeNode(tree,nodeList[it]);
		if (NULL == tree)
		{
			cout << "add " << nodeList[it] << " error!!! , tree empty" << endl;
		}
	}
}

void convertToList(BSTreeNode *node)
{
	if (NULL == pHead)
	{
		cout << "pHead is empty..." << endl;
		pHead = node;
		pCurrent = pHead;
		return;
	}
	else
	{
		//pCurrent = node;
		pCurrent->m_pRight = node;
		node->m_pLeft = pCurrent;
		pCurrent = node;
	}

}

void inOrder_traverse(BSTreeNode *tree)
{
	if ( NULL == tree)
	{
		//cout << "empty tree..." << endl;
		return;
	}
	inOrder_traverse(tree->m_pLeft);
	cout << tree->m_nValue << endl;
	convertToList(tree);
	inOrder_traverse(tree->m_pRight);
}


int main()
{
	vector<int> nodeList;
	BSTreeNode *tree = NULL;

	int number;
	cout << "input node , return <ctrl + D>" << endl;
	while(cin >> number)
	{
		nodeList.push_back(number);
	}

	cout << "nodeList.size() = "  << nodeList.size() << endl;
	//
	build_tree(nodeList,tree);
	if (NULL == tree)
	{
		cout << "build tree error!!!" << endl;
	}
	cout << "print tree..." << endl;
	inOrder_traverse(tree);
	BSTreeNode *tempP = pHead;
	cout << "print forward list..." << endl;
	if (NULL == pHead)
	{
		cout << "pHead is empty..." << endl;
		return 0;
	}
	while(tempP)
	{
		cout << tempP->m_nValue << endl;
		tempP = tempP->m_pRight;
	}
	cout << "print inverse list..." << endl;
	tempP = pCurrent;
	while(tempP)
	{
		cout << tempP->m_nValue << endl;
		tempP = tempP->m_pLeft;
	}
	return 0;
}
