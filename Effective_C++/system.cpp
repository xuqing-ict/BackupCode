#include <iostream>
#include <string>

using namespace std;

	const string prev = "12345";
int main()
{
	
	string cur = prev;
	cur[0] = 3;
	return 0;
}

#if 0
string& operator=(const string& rhs)
{
	if (*this != rhs)
	{

	}
}

string& operator[](int index)
{
	if(*ref > 1) {
	--*ref;
	char *old = data;
	data = new char[strlen(old)+1];
	strcpy(data, old);
	}
	return data[index];
}

~string()
{
	if (--*ref == 0)
	{
		delete [] data;
	}
}
#endif
