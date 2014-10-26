#include <iostream>
#include<algorithm>
#include<iterator>
using namespace std;


bool myFunc(double i, double j){return (i > j);}
int main()
{
	double myInts[] = {-345.45, -453.56, -342.45};
	cout << min_element(myInts,myInts+sizeof(myInts)/sizeof(double))- myInts << endl;
	cout << max_element(myInts,myInts+sizeof(myInts)/sizeof(double))- myInts << endl;
	copy(myInts, myInts + 3, ostream_iterator<double>(cout ,"\t"));
	cout << endl;
	sort(myInts, myInts + 3, myFunc);
	copy(myInts, myInts + 3, ostream_iterator<double>(cout ,"\t"));
	cout << endl;
	return 0;
}
