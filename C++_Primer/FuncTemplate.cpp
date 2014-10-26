#include <iostream>
using namespace std;

template<class T>
T myAbs(T x)
{
	if(x < 0) return (-x);
	return x;
}

template<class T, class Compare> // = less<T>() >
bool myCompare(T a, T b, const Compare &cmp)
{
	return cmp(a,b);
}

int main()
{
	cout << myAbs(-1) << endl;
	cout << myAbs(-0.35) << endl;
	cout << myCompare(1,2, less<int>())  << endl;
	cout << myCompare(4,2, less<int>())  << endl;

	return 0;
}
