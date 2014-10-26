//利用备忘录可以减少递归调用的層数
#include<iostream>
using namespace std;

const int MAX_N = 1000;
int memo[MAX_N] = {0};
int Fib(int n)
{
	if(n <= 1) return n;
	if (memo[n] != 0 ) return memo[n];
	return Fib(n-1) + Fib(n-2);
}
int main()
{
	int n = 0;
	cout << "imput n: " << endl;
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cout << Fib(i) << " ";
	cout << endl;
	return 0;
}
