/*
 *给定元素为0和1 的数组，找出最长的01个数相等的子数组的长度

 * */
#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

int Long01(int data[], int n)
{
	if(n == 0 ) return 0;
	vector<int> sum(n+1,0);

	sum[0] = 0;
	for(int i = 1 ; i <= n; ++i)
		sum[i] = sum[i-1] + ((data[i-1])?1:-1);
	
	copy(sum.begin(),sum.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	map<int, int> exist;
	map<int,int>::iterator it;
	int ret = 0;
	for(int i = 0; i <= n; ++i)
	{
		if ((it = exist.find(sum[i]) ) != exist.end())
		{
			if(ret < (i - it->second)) ret = i - it->second;
		}
		else
		{
			exist.insert(pair<int,int>(sum[i],i));
			cout << "insert " << sum[i] << " " << i << endl;
		}
	}
	if(ret % 2 == 0) return ret;
	return -1;

}

int main()
{
	int data[] = {1,0,1,1,0,0};
	int len =  sizeof(data)/sizeof(int);
	cout << Long01(data, len) << endl;
	return 0;
}
