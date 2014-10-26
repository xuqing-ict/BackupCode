#include<map>
#include<iostream>

using namespace std;

int main()
{
	map<pair<int,int>, int> m;
	m.insert(make_pair(make_pair(1,2), 3));
	map<pair<int,int>, int>::iterator it = m.begin();
	cout << (it->first).first << endl;
	return 0;
}
