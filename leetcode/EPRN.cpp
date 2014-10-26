#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<cassert>
#include<stack>
#include<cstdlib>

using namespace std;


class solution
{
private:
	static bool isdigits(const string str)
	{
		cout << "isdigits " << str << endl;
		if(str.empty())
		{
			return false;
		}
		int index = 0;
		if(str[index] == '-')
		{
			++index;
		}
		while(index < str.size() && isdigit(str[index]))
		{
			++index;
		}
		if (index == str.size())
		{
			return true;
		}
		return false;
	}
	static bool isOperation(const string str)
	{
		return (str.size() == 1) && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/');
	}

public:

int evalRPN(vector<string> &tokens) 
{
	if (tokens.empty())
	{
		return 0;
	}
	stack<int> s;

	int  i = 0;
	int num1, num2;
	while(i < tokens.size())
	{
		if(isdigits(tokens[i]))
		{
			s.push(atoi(tokens[i].c_str()));
		}
		else if(isOperation(tokens[i]))
		{
			switch(tokens[i][0])
			{
				case '+':num1 = s.top();s.pop(); num2 = s.top(); s.pop();s.push(num1+num2);break;
				case '-':num1 = s.top();s.pop(); num2 = s.top(); s.pop();s.push(num2-num1);break;
				case '*':num1 = s.top();s.pop(); num2 = s.top(); s.pop();s.push(num1*num2);break;
				case '/':num1 = s.top();s.pop(); num2 = s.top(); s.pop();s.push(num2/num1);break;
				default:exit(1);
			}
		}
		else
		{
			exit(1);
		}
		++i;
	}
}
};

int main()
{
	//string input[] = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
	string input[] = {"32","23","+"};
	vector<string> tokens(input, input + 3);
	copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout,"\t"));
	solution s;
	cout << s.evalRPN(tokens)	<< endl;
    cout << (0x1 << 32-1 )<< endl;
}

