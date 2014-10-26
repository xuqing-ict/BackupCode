#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int> > ret;
	ret.push_back(vector<int>());
	ret.push_back(vector<int>(3,1));
	cout << ret.size() << endl;
	ret[0].push_back(9);
	cout << ret[0].size() << "\t" << ret[0][0] << endl;
	return 0;
}
