#include<iostream>
#include<string>
using namespace std;
unsigned long HashString(char *lpszString)
{ 
	unsigned long ulHash = 0xf1e2d3c4;

	while (*lpszString != 0)
	  { 
	       ulHash <<= 1;
		   cout << *lpszString << "\t" << hex << ulHash << "\t" << hex << (int)*lpszString << "\t"; 
								        ulHash += *lpszString++; 
										cout<<"\t" << hex << ulHash << endl;
										    }

			    return ulHash; 
}
int main()
{
	char a[] = {'a','r','r','\\','u','n','i','t','s','.','d','a','t'};
	cout << hex << HashString(a) << endl;
	return 0;
}
