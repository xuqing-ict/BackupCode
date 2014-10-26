/*
 * 设计包含 min 函数的栈(栈)
 * 定义栈的数据结构,要求添加一个 min 函数,能够得到栈的最小元素。
 * 要求函数 min、push 以及 pop 的时间复杂度都是 O(1)
 * */

#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class Stack{
private:
	stack<int> elemStack;
	stack<int> minStack;
	int minElem;
public:
	Stack(){minElem=INT_MAX;}
	int getMin();
	void Push(int val);
	void Pop();
};
int Stack::getMin()
{
	if (minStack.empty())
	{
		cout << "Stack is empty..." << endl;
		return INT_MIN;
	}
	else
	{
		return minStack.top();
	}
}
void Stack::Push(int val)
{
	if (elemStack.empty())
	{
		elemStack.push(val);
		minStack.push(val);
	}
	else
	{
		elemStack.push(val);
		if (val < minStack.top())
		{
			minStack.push(val);
		}
		else
		{
			minStack.push(minStack.top());
		}

	}
}

void Stack::Pop()
{
	if (elemStack.empty())
	{
		cout << "Stack is empty..." << endl;
		return;
	}
	elemStack.pop();
	minStack.pop();
}


int main()
{
	Stack s1;
	s1.Push(-3);
	s1.Push(2);
	s1.Push(3);
	s1.Push(1);
	s1.Push(-5);
	cout << "s1 minimum = " << s1.getMin() << endl;
	s1.Pop();
	cout << "s1 minimum = " << s1.getMin() << endl;
	s1.Pop();
	cout << "s1 minimum = " << s1.getMin() << endl;
	s1.Pop();
	cout << "s1 minimum = " << s1.getMin() << endl;
	s1.Pop();
	cout << "s1 minimum = " << s1.getMin() << endl;
	return 0;
}
