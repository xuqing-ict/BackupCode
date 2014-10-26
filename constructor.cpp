//如果需要定义类类型的const数组，
//如果类有构造函数的话，就需要定义类的默认构造函数
//如果类没有构造函数，则不需要说明什么。
//这段程序其实没有什么用。
//常对象只能调用常成员函数。
//一般对象则可以调用所有的函数，
//对于有同名的常成员函数和一般的函数，如果非常对象调用，则优先选择非常成员函数，如果没有，就选择常成员函数。
#include<iostream>
using namespace std;

class A
{
public:
	A(){x = 10;}
	A(int x){this->x = x;}
	int getX() const
	{	
		return x;}
	//int getX()
	//{	x = 100;
		//return x;}
private:
	int x;
};

int main()
{
	int m = 5;
	const A *ptr = new const A[2]();
	cout << ptr->getX() << endl;
	cout << (ptr+1)->getX() << endl;
	A a2;
	cout << a2.getX() << endl;
 	return 0;
}
