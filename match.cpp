//括号匹配问题集：
//输入的是否匹配
//如果不匹配，那么需要至少添加多少个括号，使得匹配。
//给定括号的种类与个数，求得可能的正确的序列数
#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;
int main()
{
	stack<char> matchStack;
	string list;
	cin >> list;
	cout << "list = " << list << endl;
	if (list.size() == 0)
	{
		cout << "Input error, list.size() = 0" << endl;
		exit(0);
	}
	if (list[0] == ']' || list[0] == ')')
	{
		cout << "The first char is " << list[0] << endl;
		exit(0);
	}
	matchStack.push(list[0]);

	for(string::size_type it = 1; it != list.size(); ++it)
	{
		if( (list[it] == '(') || (list[it] == '['))
		{
			matchStack.push(list[it]);
		}
		else if (!matchStack.empty())
		{
			cout << "extra right bracket!!" << endl;
		}
	
		if ((list[it] == ')' && (matchStack.top() != '(')) || (list[it] == ']' && (matchStack.top() != '[')))
		{
			cout << "not match!!!  "  << it << "\t" << list[it] << "\t" << matchStack.top() << endl;
			exit(0);
		}
		if ((list[it] == ')' && (matchStack.top() == '(')) || (list[it] == ']' && (matchStack.top() == '[')))
		{
			matchStack.pop();
		}
		else
		{
			cout << "not match!!!" << endl;
		}		

	}
	cout << "match ..." << endl;
	return 0;
}
