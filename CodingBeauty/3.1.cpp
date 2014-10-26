#include <iostream>
#include <string.h>
using namespace std;

size_t strlen(const char *s)
{
	size_t n = 0;
	while(*(s+n))
	{
		++n;
	}
	return n;
}
const char * strstr(const char *s1, const char *s2)
{
	int  n;
	if (*s2)
	{
		while(*s1)
		{
			for(n = 0 ; *(s1+n) == *(s2+n); ++n)
			{
				if (!*(s2+n+1))
				{
					return (char *)s1;
				}
			}
			s1++;
		}
		return NULL;
	}
	else
	{
		return (char *)s1;
	}
}

bool FindStr(char *S, char *t)
{
	char *S2 = new char[strlen(S)*2+1];
	strncpy(S2,S,strlen(S));
	strncpy(S2 + strlen(S),S,strlen(S));
	S2[strlen(S2) + 1] = 0;
	cout << "S2 : " << S2 << endl;
	if(strstr(S2,t))
	{
		return true;
	}
	return false;

}

int main()
{
	char Source[] = "ABCD";
	if(FindStr(Source, "CDA"))
	{
		cout << "Find..." << endl;
	}
	else
	{
		cout << "Not Find..." << endl;
	}
	return 0;
}
