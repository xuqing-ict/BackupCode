#include<iostream>
#include<stdlib.h>
#include<array>

using namespace std;

int main()
{
	array<int,4> arr1 = {1,2,3,4};
	for (auto rit = arr1.begin() ; rit != arr1.end() ; ++rit)
		cout << *rit << " ";
	cout << endl;
	for (auto rit = arr1.rbegin() ; rit != arr1.rend() ; ++rit)
		cout << *rit << " ";
	cout << endl;

	return 0;
}
