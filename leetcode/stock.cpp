//在某一天买入，在另外一天卖出，进行这样的交易一次可得到的最大的利润。
//对于每一天的价格，计算它的后面的天中的最大值即可。
//在这n个值中找出最大的即可。
//思想：第i天买入的话，那么肯定要在第[i...n]天中选择最大值的那一天卖出。

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

//利用直观的方案得到，直接求每个元素之后的最大值。
int maxProfit1(vector<int> &prices)
{
	cout << "maxProfit" << endl;
	int len = prices.size();
	int *max = new int[len];
	cout << "len = " << len << endl;
	
	max[len-1] = prices[len-1];
	cout << "max[len-1] = " << max[len-1] << endl;

	for(int i = len-2; i >= 0; --i)
	{
		//cout << "i = " << i << endl;
		if( prices[i] > max[i+1]) 
			max[i] = prices[i];
		else
			max[i] = max[i+1];
	}
	cout << "max = ";
	for(int i = 0; i < len; ++i)cout << max[i] << endl;
	cout << endl;

	int maximum = 0;

	for(int i = 0; i < len-1; ++i)
	{
		if (max[i+1] - prices[i] > maximum)
		{
			maximum = max[i+1] - prices[i];
		}
	}
	delete [] max;
	return maximum;

}
//利用Divide and Conquer
//中间merge的最大值，应该是左边的最小值与右边的最大值形成的值。
int maxProfit2(vector<int> prices, int left, int right)
{
	cout << "maxProfit2: " << left << " " << right << endl;

	int i;
	int min1, max2, maxLR, maxL,maxR;
	int mid;

	if (left < right)
	{
		mid = left + (right-left)/2;
		maxL = maxProfit2(prices,left,mid);
		maxR = maxProfit2(prices,mid+1,right);
		
		//求出maxL和maxR之后,merge的时候考虑左边的最小值和右边的最大值,在三者之间求一个最大值。
		min1 = prices[left];
		i = left;
		while(i <= mid && min1 > prices[i] )
			min1 = prices[i++];

		max2 = prices[mid+1];
		i = mid+1;
		while(i <= right && max2 < prices[i] )
			max2 = prices[i++];
		maxLR = max2-min1;
		return max(max(maxL,maxR),maxLR);
	}
	return 0;
}

int main()
{	
	srand(time(NULL));
	int len = rand()%10;
	vector<int> prices;
	for(int i = 0 ; i < len ; ++i)
		prices.push_back(rand()%10);
	/*int len = 6;
	vector<int> prices;
	int data[] = {0,1,3,2,1,3};
	for(int i = 0 ; i < len ; ++i)
		prices.push_back(data[i]);
*/
	cout << "prices len = " << prices.size()  << " " << len << endl;

	print(prices);
	int ret;

	ret = maxProfit1(prices);
	cout << "maxProfit1 = " << ret << endl;
	ret = maxProfit2(prices,0, len-1);
	cout << "maxProfit2 = " << ret << endl;

}
