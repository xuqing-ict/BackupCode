#include <iostream>
#include <memory>
using namespace std;

//nullptr的用处！！
double func(std::pair<const char *, double> p)
{
	cout << "call func..." << endl;
	return p.second;
}

int main()
{
	cout << func(std::make_pair(nullptr,3.14)) << endl;

	//share_ptr vs. weak_ptr 
	int *val = new int(10);
	shared_ptr<int> pa (val);
	//shared_ptr<int> pa1 (val); // 这样就表示将同一份资源交给了两个资源管理对象！！！不符合RAII技术。
	shared_ptr<int> pa1(pa); //因此，对于val所指向的空间只能通过智能指针pa来进行操作
	pa.reset();
	cout << *pa1 << endl;
	/*
	weak_ptr<int> pw(pa);
	cout << *pa << endl;
	cout << *(pw.lock()) << endl; //weak ptr指向的对象只能使用lock函数得到它的shared _ptr指针才能访问到该资源
//	cout << *pw << endl; //error
	//delete val;
	if(pa.unique())
	{
		cout << "pa.unique() == " << pa.unique() << endl;
		pa.reset();
	}
	cout << *pa1 << endl;
	cout << "val : " << *val << endl;

	cout << *pa << endl;
	if(pw.lock())
		cout << *(pw.lock()) <<endl;
	if(pa.unique())
	{
		cout << "pa.unique() == " << pa.unique() << endl;
		cout << *pa << endl;
	}
	pa.reset(); // equal to  shared_ptr<int>().swap(this);
	//(shared_ptr<int>()).swap(pa);
	if(pa == nullptr)
	{
		cout << "pa is null" << endl;
	}
	else
	{
		cout << "pa is not null.." << endl;
	}

	//the 
	if(pw.expired())
	{
		cout << "weak ptr is expired..." << endl;
	}
	else
	{
		cout << "weak ptr is not expired..." << endl;
		cout << *(pw.lock()) << endl;
	}
	*/
	return 0;
}
