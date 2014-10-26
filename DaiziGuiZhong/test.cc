#include <iostream>
#include <functional>
using namespace std;

struct Test
{
	int a;
};

void print(const Test& t)
{
	cout << t.a << endl;
}

int main(void)
{
	print(Test());
	cout << less<int>()(1, 2) << endl;
    string s = "-1234l";
    cout << s << endl;
    copy(s.begin()+1,s.end(),s.begin());
    cout << s<< endl;
	return 0;
}
