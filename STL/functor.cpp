//仿函数，针对某个class重载()操作符，该结构即是一个仿函数
#include <iostream>
using namespace std;

template<class T>
struct add
{	
	T operator()(const T& x, const T& y){return x+y;}
};

template<class T>
struct sub
{
	T operator()(const T& x, const T& y) {return x-y;}
};


int main()
{
	add<int> addObj;
	sub<int> subObj;
	cout << addObj(2,5) << endl;
	cout << subObj(5,2) << endl;
	
	cout << add<int>()(2,5) << endl;
	cout << sub<int>()(5,2) << endl;
	return 0;
}

