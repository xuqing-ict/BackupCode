#include<iostream>
using namespace std;

//const修饰值传递不能作为重载,因为修改的也是形式参数
//const修饰指针和引用可以作为重载
int add(const int &x)
{
	cout << "x = " << x << endl;
	return x;

}

int add(int &x)
{
	return x;
}
int main()
{
	int i = 0;
	cout << add(i) << endl;
}
