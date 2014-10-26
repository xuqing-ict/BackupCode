#include<iostream>

#include<stdlib.h>

using namespace std;

int Fib(int n)
{
	if(n==0)return 0;
	if (n==1)return 1;
	int *backup = new int[n];
	backup[0] = 0;
	backup[1] = 1;

	for(int i = 2 ; i < n ; ++i)
		backup[i] = backup[i-1] + backup[i-2];
	return backup[n-1];

}

int main()
{
	for(int j = 0 ; j < 10; ++j)
		cout << Fib(j) << " ";
	cout << endl;
	return EXIT_SUCCESS;
}
