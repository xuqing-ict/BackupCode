#include <bits/stdc++.h>
using namespace std;

void reverse(char *s)
{
/*	cout << "s : " << s<< endl;
	if(s == NULL || s[0] == '\0') return;
	int i = 0 , j = 0;
	while(s[j]) ++j;
	--j;
	while(i<j)
	{
		swap(s[i],s[j]);
		++i;--j;
	}
	cout << "s : " << s << endl;
	*/
	char *end =s ;
	if(s)
	{
		while(*end) ++end;
	}
	--end;
	while(s < end)
	{
		swap(*s,*end);
		++s;--end;
	}
}
int main()
{
	char a[] = "1234567";
	reverse(a);
	cout << a << endl;
	int  i = 0;
	char b[100];
	cin.getline(b,100);//getline会自动在末尾添加结束符'\0'
	cout << b << endl;
	cout << strlen(b) << endl;
	reverse(b);
	cout << b << endl;
	return 0;
}
