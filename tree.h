#ifndef _TREE_H
#define _TREE_H

#include<iostream>
#include<string>

using namespace std;

//类的声明与友元函数的声明大致是一样的。

template<typename T>//由于友元函数中使用了类，而友元函数又必须声明类定义之前，因此需要首先声明类。
class TreeNode;

//对于友元函数的声明，由于需要操作的类是模板类，因此需要事先声明函数。
template<typename T>
void preOrder(TreeNode<T> *tree);
template<typename T>
void inOrder(TreeNode<T> *tree);
template<typename T>
void posOrder(TreeNode<T> *tree);

template <typename T>
class TreeNode
{
	//声明类的友元函数，由于函数是模板函数，因此这里的T与类的定义的T是一致的。
	friend void preOrder<T>(TreeNode<T> *tree);
	friend void inOrder<T>(TreeNode<T> *tree);
	friend void posOrder<T>(TreeNode<T> *tree);

private:
	T value;
	TreeNode<T> *left;
	TreeNode<T> *right;
public:
	TreeNode();
	TreeNode(const T& value);
	TreeNode(const T& value,TreeNode<T> *left,TreeNode<T> *right);
	//~TreeNode();

	//get
	const T getValue();
	TreeNode<T> * getLeft();
	TreeNode<T> * getRight();

	//set
	void setValue(T value);
	void setLeft(TreeNode<T> *left);
	void setRight(TreeNode<T> *right);
	
	void delTree(TreeNode *tree);

	bool isEmpty() const;
	int treeDepth(TreeNode *tree);


};


#endif
