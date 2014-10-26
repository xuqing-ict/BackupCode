#include <iostream>       // std::cout
#include <stack>          // std::stack
#include<algorithm>

int main ()
{
	std::stack<int> foo,bar;
	foo.push (10); foo.push(20); foo.push(30);
	bar.push (111); bar.push(222);

	foo.swap(bar); //both *this and bar are modified.
	//swap(foo,bar); // both foo and bar are modified.
	
	std::cout << "size of foo: " << foo.size() << '\n';
	while(!foo.empty())
	{
		std::cout << foo.top() << std::endl;
		foo.pop();
	}
	while(!bar.empty())
	{
		std::cout << bar.top() << std::endl;
		bar.pop();
	}
	std::cout << "size of bar: " << bar.size() << '\n';

	return 0;
}
