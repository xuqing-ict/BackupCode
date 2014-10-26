#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str1[] = "To be or not to be";
	cout << "sizeof [] : "  << sizeof(str1) << endl;  //str1占用的内存空间
	cout << "strlen [] : " << strlen(str1) << endl;  //str1中的字符个数。不包含'\0'
	str1[4] = 0;
	cout << "sizeof [] : "  << sizeof(str1) << endl;  //str1占用的内存空间
	cout << "strlen [] : " << strlen(str1) << endl;  //str1中的字符个数。不包含'\0'


	char str2[40];

	cout << "sizeof [40] : " << sizeof(str2) << endl;
	cout << "strlen [40] : " << strlen(str2) << endl;

	char str3[40];

	strncpy(str2,str1,sizeof(str2));
	
	cout << str2 << endl;
	cout << "str2.sizeof() = " << sizeof(str2) << endl;
	cout << "str2 strlen() = " << strlen(str2) << endl;
	
	strncpy(str3,str1,5);
	str3[5] = 0; //必须手动加上'\0'
	return 0;
}
