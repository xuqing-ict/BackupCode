#include<iostream>

using std::endl;
using std::cout;

class Nesting{
private:
	int val;
	class child{
	private:
		int val2 = 3;
	public:
		void getVal2(){cout << "val2 = " << val2 << endl;;}
	};
public:
	child c;
	void getVal(){cout << "val = " << val << endl;}
};


int main()
{
	Nesting ne1;
	ne1.c.getVal2();
	return 0;
}
