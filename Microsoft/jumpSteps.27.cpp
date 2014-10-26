#include <iostream>
#include <vector>
#include <time.h>

time_t start, end;
double seconds;

using namespace std;

long jump1Or2Steps(const int n)
{
	if (n == 0 || n== 1)
	{
		return 1;
	}
	return jump1Or2Steps(n-1) + jump1Or2Steps(n-2);
}

long  long jump2(const int n)
{
	vector<long long > steps(n+1,0);
	steps[1] = 1;
	steps[0] = 1;
	for(int i = 2 ; i <= n ; ++i)
	{
		steps[i] = steps[i-1] + steps[i-2];
		cout << i << "\t" << steps[i] << endl;
	}
	return steps[n];

}
int main()
{
	int n = 20;
	time(&start);
	cout << jump2(n) << endl;
	time(&end);
	
	seconds = difftime(end,start);
	cout << "running time = " << seconds << " seconds " << endl;

	time(&start);
	cout << jump1Or2Steps(n) << endl;
	time(&end);


	seconds = difftime(end,start);
	cout << "running time = " << seconds << " seconds " << endl;

	return 0;
}
