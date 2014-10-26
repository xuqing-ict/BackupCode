#include<iostream>
#include<stdlib.h>

using namespace std;

int deleteM(int n, int m)
{
	if( n == 0) return -1;
	if( n == 1) return 0;
	for(int i = 1; i < n ; ++i)
	{
		return ( deleteM( n-i, m ) + m ) % n;
	}
	
}
int main()
{
	int n = 5, m = 3;
	cout <<deleteM(n,m) << endl;

	return EXIT_SUCCESS;
}

