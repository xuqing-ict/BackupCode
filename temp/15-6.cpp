#include<iostream>
using namespace std;

const int n = 3;

int max(int x, int y, int z)
{
	if (x>y)
		return (x>z)?(x):(z);
	else
		return (y>z)?(y):(z);
}
int main()
{
	int cost[n][n] = {0};
	int node[n][n] = {0};
	int number = 0;
	int cost1 = 0;
	int cost2 = 0;
	int cost3 = 0;
	cout  << "please input " << n << "*" << n << " numbers to nodes" << endl;
	int i = 0;
	int j = 0;

	while(cin >> number)
	{
		if (j == n)
		{
			i++;
			j=0;
		}
		if (i == n)
			break;
		node[i][j] = number;
		cout << "node[" << i <<"]" << "[" << j << "]" << "=" << node[i][j] << endl;
		j++;
	}
	for(i = 0; i < n; ++i)
	{
		cost[1][i] = node[1][i];
	}
	for(i = 1 ; i < n; ++i )
	{
		for (j = 0; j < n ; ++j )
			if (j == 0)
			{
				cost1 = 0;
				cost2 = cost[i-1][j];
				cost3 = cost[i-1][j+1];
				cost[i][j] = max(cost1,cost2,cost3) + node[i][j];
				continue;
			}
			if (j == n-1)
			{
				cost1 = cost[i-1][j-1];
				cost2 = cost[i-1][j];
				cost3 = 0;
				cost[i][j] = max(cost1,cost2,cost3) + node[i][j];
				continue;
			}
			cost1 = cost[i-1][j-1];
			cost2 = cost[i-1][j];
			cost3 = cost[i-1][j+1];
			cost[i][j] = max(cost1,cost2,cost3) + node[i][j];
	}
	for(i = 0; i < n; ++i)
		for( j = 0; j < n; ++j)
			cout << cost[i][j] <<  " ";
		cout << endl;
	return 0;
}
