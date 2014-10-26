#include <iostream>
using namespace std;

struct Foo
{
	Foo(){}
	Foo(int){}
	void fun() {}
};
int main()
{
	Foo a(10);
	a.fun();
	//Foo b(); //error . 这样是函数声明了！！！ 
	//b.fun();

	const char *p1 = "Hello";
	char * const p2 = "World";

	p1++;
	//*p1 = "w";
	//p2++;
	//*p2 = "h";
	cout << p1 <<" " << p2 << endl; 
	return 0;
}
