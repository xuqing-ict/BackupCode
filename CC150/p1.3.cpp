#include <bits/stdc++.h>
using namespace std;

bool isSameWord(string s, string t)
{
	if (s.size() != t.size())
	{
		return false;
	}
	int exist[256] = {0};
	
	for(auto c : s)
		exist[c]++;
	for(auto c: t)
	{
		if(--exist[c] < 0)
			return false;
	}
	return true;
	
}
int main()
{
	string s = "12 345  ";
	string t = "3451  2 ";
	cout << isSameWord(s,t) << endl;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	cout << (s==t) << endl;
	return 0;
}
