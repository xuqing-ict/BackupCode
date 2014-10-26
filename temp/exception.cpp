#include<iostream>
#include<stdexcept>

using namespace std;

void print(int x)
{
	try
	{
		if(x == 0)
		{
			throw runtime_error("exception in print function...");
		}
	}
	catch(overflow_error err){
		cout << "catch in print function..." << err.what() << endl;	
	}
}

int main()
{
	int x;
	while(cin >> x)
	{
		try
		{
			if (x == 0)
			{
				print(x);
				throw runtime_error("input is 0...");
				//return 1;
			}
		}catch(runtime_error err){
			cout << "catch in main..." << err.what() << endl;
			return 1;
		}
	}
	return 0;
}
