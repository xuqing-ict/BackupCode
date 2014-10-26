#include<iostream>
#include <typeinfo>
using namespace std;

int main()
{
	int iVal = 5;
	cout << typeid(iVal).name() << endl;
	double dVal = 10.0;
	cout << typeid(dVal).name() << endl;
	float fVal = 0 ;
	cout << typeid(fVal).name() << endl;
	cout << typeid(int(fVal)).name() << endl;

    const int val = 100;
    double cVal = static_cast<double>(val);
    cout << val << endl;
    cout << cVal << endl;
    cVal = 10;
    cout << val << endl;
    cout << cVal << endl;
    int x=100;
    const int &cx=x;
    const int &cy=x+1;
    cout << "x : " << &x  << " " << x << endl;
    cout << "cx : " << &cx <<  " " << cx << endl;
    cout << "cy : " << &cy <<  " " << cy << endl;
    x = 102;
    cout << "x : " << &x  << " " << x << endl;
    cout << "cx : " << &cx <<  " " << cx << endl;
    cout << "cy : " << &cy <<  " " << cy << endl;
	return 0;
}
