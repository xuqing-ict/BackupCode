#include<iostream>
#include<sstream>
using namespace std;
struct test{
	int a;
	int b;
};

ostream & operator<<(ostream &os, const test & t)
{
	os << t.a << " " << t.b << endl;
}
int main()
{
	test t1;
	t1.a = 2;
	t1.b = 3;
	cout << t1 << endl;

	string s = "12 34";
	istringstream line(s);
	string word;
	line >> word;
	cout << word << endl;
	line >> word;
	cout << word << endl;


}
