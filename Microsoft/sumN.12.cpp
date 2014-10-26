#include<iostream>
#include<cassert>
#include<cstdlib>

using namespace std;

int sumN(int n)
{
	int ret = 0;
	(n)&&(ret += sumN(n-1));
	ret += n;
	return ret;
}

int main()
{
	int n;
	cout << "Input a integer.." << endl;
	cin >> n;
	cout << sumN(n) << endl;
	return EXIT_SUCCESS;
}
