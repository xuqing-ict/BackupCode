#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void leftRotate(string &s, const int k)
{
	if(s.empty())
	{
		return;
	}
	reverse(s.begin(),s.begin()+k);
	reverse(s.begin()+k,s.end());
	reverse(s.begin(), s.end());
}
int main()
{
	string input = "1234567890";
	int k = 3;
	cout << input << endl;
	leftRotate(input,k);
	cout << input << endl;
	return 0;
}
