#include <iostream>
#include <string.h>

using namespace std;

char f(char *x)
{
	++x;
	*x = 'a';
	return *x;
}

int main()
{
	char str[sizeof("hello")];
	cout << sizeof("hello") << endl;
	strcpy(str, "hello");
	f(str);
	cout << str << endl;

	char str2[] = "HELLO";
	cout << str2 << endl;

	return 0;
}
