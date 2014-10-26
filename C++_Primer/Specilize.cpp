#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;


template <class T>
int compare(const T & a, const T & b)
{
	cout << "call compare template..." << endl;
	cout << a << " " << b << endl;
	if (a < b ) return -1;
	if (b < a)  return 1;
	return 0;
}

template<>
int compare<const char *>(const char* const &a, const char* const &b)
{
	cout << "call compare Speciatize..." << endl;
	return strcmp(a,b);
}

int main()
{
	const char *a = "Hello";
	const char *b = "World";
	cout << compare(a,b) << endl;
	cout << compare("Hello", "World") << endl;
	return 0;
}
