#include<iostream>
#include<vector>
using namespace std;
int array_out[5];
int main()
{
	int a = 512;
	int n = a+1;
	int b[n];
	b[0] = 0;
	b[4] = 9;
	cout << b[0] << endl;
	cout << b[4] << endl;
	cout << b << endl;
	cout << &(b[a]) << endl;
	int array_in[5];
	int array_in_init[5] = {1,2,3};
	cout << "array_out[0] = " << array_out[0] << endl;
	cout << "array_in[0] = " << array_in[0] << endl;
	cout << "array_in_init[0] = " << array_in_init[0] << endl;
	for(int i=0;i<5;i++)
		cout << "array_in_init["<<i<<"] = " << array_in_init[i] << endl;
	//vector<int> ivec(7,0) = {0,1,2,3,4,5,6};
	//for(int i=0;i<7;i++)
		//cout << "ivec["<<i<<"] = " << ivec[i] << endl;
	//int ia[] = ivec;

	
	const int ival = 50;
	int ival2 = 51;
	const int *p = &ival;
	cout << "*p = " << *p << endl;
	p = &ival2;
	//*p = *p + 1;  //error
	cout << "*p = " << *p << endl;
	return 0; 
}
