#include "tree.h"
template <typename T>
TreeNode<T>::TreeNode()
{
	left = NULL;
	right = NULL;
}
template<typename T>
TreeNode<T>::TreeNode(const T& value)
{
	this->value = value;
}
template <typename T>
TreeNode<T>::TreeNode(const T& value, TreeNode<T> *left, TreeNode<T> *right)
{
	this->value = value;
	this->left = left;
	this->right = right;
}
/*
template<typename T>
TreeNode<T>::~TreeNode()
{
	delete left;
	delete right;
	delete this;
}
*/

template<typename T>
bool TreeNode<T>::isEmpty() const
{
	return (this)?true:false;
}
template<typename T>
int TreeNode::treeDepth(TreeNode *tree)
{
	if (!tree)
	{
		return 0;
	}
	if (tree->left)
	{
		return treeDepth(tree->left) + 1;
	}
	if (tree->right)
	{
		return treeDepth(tree->right) + 1;
	}

}
template<typename T>
void TreeNode<T>::delTree(TreeNode *tree)
{
	if (NULL == tree)
	{
		return;
	}
	delTree(tree->left);
	delTree(tree->right);

	delete tree;
}

template<typename T>
const T TreeNode<T>::getValue()
{
	return value;
}
template<typename T>
TreeNode<T>* TreeNode<T>::getLeft()
{
	return left;
}
template<typename T>
TreeNode<T>* TreeNode<T>::getRight()
{
	return right;
}
template <typename T>
void TreeNode<T>::setValue(T value)
{
	this->value = value;
}
template<typename T>
void TreeNode<T>::setLeft(TreeNode<T> *left)
{
	this->left = left;
}
template<typename T>
void TreeNode<T>::setRight(TreeNode<T> *right)
{
	this->right = right;
}
template<typename T>
void preOrder(TreeNode<T> *tree)
{
	if (NULL == tree)
	{
		return;
	}
	cout << tree->value << endl;
	preOrder(tree->left);
	preOrder(tree->right);
}
template<typename T>
void inOrder(TreeNode<T> *tree)
{
	if (NULL == tree)
	{
		return;
	}
	inOrder(tree->left);
	cout << tree->value << endl;
	inOrder(tree->right);
}

template<typename T>
void posOrder(TreeNode<T> *tree)
{
	if (NULL == tree)
	{
		return;
	}
	posOrder(tree->left);
	posOrder(tree->right);
	cout << tree->value << endl;
}

int main()
{
	const int value = 10;
	const int value2 = 20;
	const int value3 = 30;
	TreeNode<int> tree1(value,NULL,NULL);
	cout << "tree->value = " << tree1.getValue() << endl;
	TreeNode<int> tree2(value2,&tree1,NULL);
	cout << "tree2->value = " << tree2.getValue() << endl;
	cout << "tree2->left->value = " << tree2.getLeft()->getValue() << endl;
	TreeNode<int> tree3(value3, &tree1,&tree2);
	cout << "preOrder ";
	preOrder(&tree3);
	cout << endl;
	cout << "inOrder ";
	inOrder(&tree3);
	cout << endl;
	cout << "posOrder ";
	posOrder(&tree3);


	return 0;
}
