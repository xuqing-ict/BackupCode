#include <iostream>
#include <stdlib.h>
#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

int str2Int(string s)
{
	if (s.empty())
	{
		throw runtime_error("Input Invalid!!!");
		exit(1);
	}
	int  i = 0;
	int number = 0;
	bool flag = false;
	if(s[0] == '+' || s[0] == '-')
	{
		++i;
		flag = true;
	}
	for(; i < s.size() ; ++i)
	{
		if (!isdigit(s[i]))
		{
			throw runtime_error("Input Invalid");
			exit(1);
		}
		number = number * 10 + (s[i] - '0');
	}
	if(flag)
	{
		number = -number;
	}
	return number;
}

int main()
{
	string s;
	cin >> s;
	int num = str2Int(s);
	cout << num << endl;
}
