#include<iostream>
#include<cstdlib>
using namespace std;




int &geitis(int *cc , int bb);
int &geitis(int *cc , int bb);
int &geitis(int * , int);

int &getia(int *arry , int index)
{
	return arry[index];
}

int main()
{
	int ia[10] = {1,2,3,4,5,6,7,8,9,0};
	for(int i = 0 ; i != 10; ++i)
		cout << ia[i] << endl;
	for(int i = 0 ; i != 10; ++i)
		getia(ia,i) = 0;
	for(int i = 0 ; i != 10; ++i)
		cout << ia[i] << endl;
	return EXIT_SUCCESS;
}

