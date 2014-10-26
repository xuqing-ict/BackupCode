#include "String.h"

#include <iostream>

using namespace std;

int main()
{
	String s = "abcd";
	cout << "s = " << s << endl;
		
	String s1;
	cout << "s1 = " << s1 << endl;

	String s2 = s;
	cout << "s2 = " << s2 << endl;
	cout << (void *)(s2.c_str()) << "\t" << (void *)(s.c_str()) << endl;
	
	String s3;
	s3 += s;
	cout << "s3 = " << s3 << endl;
	s3[0] = 'M';
	cout << "s3[0] = M " << s3 << endl;

	String s4 = s3 + s2;
	cout << "s4 = s3 + s2 " << s4 << endl;
	return 0;
}
