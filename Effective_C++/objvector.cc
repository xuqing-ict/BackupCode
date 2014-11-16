#include<iostream>
#include<vector>

using namespace std;

class Test
{
private:
	int val;
public:
	Test(int x = 0):val(x){cout << "Test ctor..." << endl;}
	~Test()
	{
		cout << "val = " << val << endl;
	}
	void set_val(int x)
	{
		val = x;
	}
};

int main()
{
	vector<Test> iVec(5);
	cout << "begin set val..." << endl;

	for(int i = 0; i < 5; ++i)
	{
		(iVec[i]).set_val(i);
	}
	return 0;
}
