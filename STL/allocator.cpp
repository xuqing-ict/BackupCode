#include<iostream>
using namespace std;

int main()
{
	int iVal = 5;
	int *p;
	p.address(iVal);
	cout << iVal << &iVal <<endl;
	cout << *p << p << endl;

}
