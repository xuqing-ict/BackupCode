#include <bits/stdc++.h>
using namespace std;

bool exist(string s)
{
	bool exist[256] = {false};
	for(int i = 0 ; i < s.size() ; ++i)
	{
		cout << s[i] << endl;
		if(exist[s[i]]) return false;
		exist[s[i]] = true;
	}
	return true;
}
int main()
{
	string s;
	cin >> s;
	if(exist(s)) 
		cout << "Suc.." << endl;
	else
		cout << "fail..."<< endl;
	return 0;
}
