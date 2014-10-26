#include<iostream>
using namespace std;
template<class T>
class test
{
	friend void printVal(test<T> *obj);
private:
	T value;
	test(T value);
public:
	void getValue();
};
template<class T>
void test::getValue()
{
	return value;
}

template<class T>
test::test(T value)
{
	this->value = value;
}
template<class T>
void printVal(test<T> *obj) 
{
	cout << obj->value << endl;
}
int main()
{
	test<int> obj(10);
	cout << "obj.value = " << obj->getValue() << endl;
	printVal(obj);



	return 0;
}
