#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

time_t start, end;
double seconds;

int count(int A[], int n)
{
	for(int i = 0 ; i < n; ++i)
	{
		int count = A[i];
		int ret = 0;
		while(count)
		{
			ret += (count%2);
			count /=2;
		}
		//return ret;
	}
	return 0;
}

int count2(int A[], int n)
{
	for(int i = 0; i < n ; ++i)
	{
		int count = A[i];
		int ret = 0;
		while(count)
		{
			ret += (count%2);
			count >>= 1;
		}
		//return ret;
	}
	return 0;
}

int count3(int )

int main()
{
	const int N = 10000;
	int A[10000] = {0};

	for(int i = 0 ; i < N ; ++i)
	{
		A[i] = rand() % 1000000;
	}

	time(&start);
	cout << count(A, N) << endl;
	time(&end);
	seconds = difftime(end, start);
	cout << "time : " << seconds << " s" << endl;

	time(&start);
	cout << count2(A, N) << endl;
	time(&end);
	seconds = difftime(end, start);
	cout << "time : " << seconds << " s" << endl;

	return 0;
}
