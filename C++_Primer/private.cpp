#include <iostream>

using namespace std;


class C
{
private:
	int code;
public:
	C(int _code):code(_code){}
	bool operator==(const C &c2);
};


bool C::operator==(const C &c2)
{
	cout << "c2.code = " << c2.code << endl;
	if (code = c2.code)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	C c1(2);
	C c2(2);
	if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2 " << endl;
	}

	return 0;
}
