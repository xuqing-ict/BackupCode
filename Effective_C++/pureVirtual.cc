//类的纯虚函数也可以有自己的定义
//虽然该纯虚函数有自己的定义，但是该类还是不能定义对象
#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base() = 0;
	virtual void Func() = 0 ;

};
//如果将析构函数声明为virtual，那么必须为改虚函数定义函数体
//因为每一个派生类的析构函数都会被编译器加以扩张，以静态的方式调用其”每一个“
Base::~Base()
{
    cout << "pure virtual dtor..." << endl;
}

void Base::Func()
{
	cout << "Base virtual call" << endl;
}
class Derived:public Base
{
public:
	void Func()
	{
		Base::Func();
		cout << "Derived virtual call" << endl;
	}
};

int main()
{
    //Base::Func();
	Derived d;
	d.Func();
	return 0;
}
