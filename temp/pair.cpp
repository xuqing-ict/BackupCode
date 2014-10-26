#include<iostream>
using namespace std;
struct A{};
int main()
{
	pair<int, int> P = make_pair(1,2);
	cout << P.first << " " << P.second << endl;
	cout << "A size = " << sizeof(A) << endl;
	return 0;
}
