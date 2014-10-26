#include<iostream>
using namespace std;
int i = 4;
int main()
{
	int i = i;
	cout << "i = " << i << endl;
	int a,x;
	for(a=0,x=0;a<=1 &&!x++;a++)
	{
		a++;
	}
	cout << a << " " << x << endl;
	for(a=0,x=0;a<=1 &&!x++;)
	{
		a++;
	}
	cout << a << " " << x << endl;
	int list[] = {1,2,3,4,5};
	int *ptr = list;
	//cout <<  *ptr<< " " <<*(ptr++) << " " << *ptr << endl;
	cout << *(++ptr)+133 << " " << *(ptr) << " " << *(++ptr) << endl;
	string s1("123456");

	if(isalnum(s1[0]))
	{
		cout << "s1[0] is a number or char..." << isalnum(s1[0]) << endl;
		
	}
	string s2 = "HELLO,world1!!";
	cout << "s2 = " << s2 << endl;
	for(string::size_type st = 0; st != s2.size(); st++)
	{
		s2[st] = toupper(s2[st]);
	}
	cout << "s2 = " << s2 << endl;
	return 0;
}
