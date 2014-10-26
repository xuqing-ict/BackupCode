#include<iostream>

using namespace std;

int main()
{
	int iNum = 0;
	double dNum = 5.4;
	cout << sizeof(int) << " " << sizeof(double) << endl;
	cout << "sizeof() = " << sizeof(dNum = iNum + 3) << endl;
	cout << dNum << endl;

	return 0;
}
