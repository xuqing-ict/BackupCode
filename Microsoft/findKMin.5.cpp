/*
 * 5.查找最小的 k 个元素(数组)
 * 题目:输入 n 个整数,输出其中最小的 k 个。
 * 例如输入 1,2,3,4,5,6,7 和 8 这 8 个数字,则最小的 4 个数字为 1,2,3 和 4。
 * */

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> findKMin(vector<int> data, int k)
{
	vector<int> kMinVals;
	size_t len = data.size();
	if (k >= len) return data;
	priority_queue<int> kMin;
	for(int i = 0 ; i < len ; ++i)
	{
		if (kMin.size() < k)
			kMin.push(data[i]);
		else
		{
			if(data[i] < kMin.top())
			{
				kMin.pop();
				kMin.push(data[i]);
			}
		}
	}
	while(!kMin.empty())
	{
		kMinVals.push_back(kMin.top());
		kMin.pop();
	}
	return kMinVals;
}



int main()
{
	srand(time(NULL));
	//int len = rand()%20;
	 
	int k = rand()%10;
	cout << "k = " << k << endl;
	
	int a[] = { 60, 23, 76, 73 , 65 , 25 , 75, 58, 50 ,35 ,6 ,78 ,64 ,36};
	int len = sizeof(a)/sizeof(int);

	vector<int> data( a , a + len);
	/*
	for(int i = 0 ; i < len ; ++i )
		data.push_back(rand()%100);
	cout << "data = ";
	*/
	for(size_t i = 0 ; i < data.size() ; ++i)
		cout << data[i] << " ";
	cout << endl;
	cout << "find k min = ";
	vector<int> kMinVec = findKMin(data, k);
	for(size_t i = 0 ; i < kMinVec.size() ; ++i)
		cout << kMinVec[i] << " ";
	cout << endl;
	
	sort(data.begin() , data.end() );
	
	for(size_t i = 0 ; i < data.size() ; ++i)
		cout << data[i] << " ";
	cout << endl;
	
	return 0;
}
