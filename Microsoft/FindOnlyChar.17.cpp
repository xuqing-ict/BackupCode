#include<iostream>
#include<string>

using namespace std;

int count[255]= {0};

char FindOnlyChar(string s)
{
	if(s.size()==0)
		return 0;
	for(string::size_type i = 0; i< s.size(); ++i)
	{
		count[s[i]-'a']++;
	}

	for(string::size_type i = 0; i< s.size(); ++i)
		if (count[s[i]-'a']==1)
			return s[i];
	return 0;
}

int main()
{
	string str("abaccdeff");
	cout << "answer = " << FindOnlyChar(str) << endl;
	return 0;
}

