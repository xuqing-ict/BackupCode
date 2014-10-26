#include <bits/stdc++.h>
using namespace std;
string compress(const string &s)
{
	if(s.empty()) return s;
	int  i = 0;
	string ret;
	while(i < s.size())
	{
		char c = s[i];
		int count=0;
		while(i < s.size() && s[i] == c){ ++count;++i;}
		ret += ('0' + count);
		ret += c;
	}
	if(ret.size() == s.size()) return s;
	return ret;
}
int main()
{
	string s = "baaaabbcc";
	cout << compress(s) << endl;
	return 0;
}
