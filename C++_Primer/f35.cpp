#include <iostream>
#include <time.h>
using namespace std;

int f(int x)
{
	int s = 0;
	while(x-- > 0) s += f(x);

	return max(s,1);
}


int main()
{
	time_t start,end;

	time(&start);
	cout << f(35) << endl;
	time(&end);
	double seconds = difftime(end, start);
	cout << "time = " << seconds << endl;
	return 0;
}
