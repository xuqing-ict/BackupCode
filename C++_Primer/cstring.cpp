#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char p[] = "ABCD";
	char a[7] = {'A','B','C','D'};
	if (!strcmp(p,a))
	{
		cout << "YES!" << endl;
	}
	return 0;
}
