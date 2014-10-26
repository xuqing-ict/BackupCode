//在某一天买入且在改天后的某一天卖出，允许这样进行买卖多次，计算能够得到的最大的利润。（手中不允许同时有多张！）
//greedy的思想:
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<assert.h>
#include<vector>
using namespace std;


void print(vector<int> A )
{
	for(vector<int>::size_type i = 0; i != A.size() ; ++i)
		cout << A[i] << " ";
	cout << endl;
}

int maxProfit1(vector<int> &prices)
{
	int len = prices.size();
	int i = 0;
	int left, right;
	int profit=0;
	while(i < len)
	{
		left = prices[i];
		while((i < (len-1)) && (prices[i] < prices[i+1]))i++;
		if (i < len)right = prices[i];
		profit += (right-left);
		i++;
	}
	return profit;
    }





int main()
{	/*
	srand(time(NULL));
	int len = rand()%10;
	vector<int> prices;
	for(int i = 0 ; i < len ; ++i)
		prices.push_back(rand()%10);
	 */
	int len = 2;
	vector<int> prices;
	int data[] = {2,1};
	for(int i = 0 ; i < len ; ++i)
		prices.push_back(data[i]);

	cout << "prices len = " << prices.size()  << " " << len << endl;

	print(prices);
	int ret;

	ret = maxProfit1(prices);
	cout << "maxProfit1 = " << ret << endl;

}
