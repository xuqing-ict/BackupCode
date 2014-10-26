//二分查找有序数组，返回查找元素第一次出现的位置
// 边界情况很重要，
// 必须保证我没次查找的字数组中包含我要查找的元素！！！
#include<iostream>
using namespace std;

int binarySearch(int A[], int data, int left, int right)
{
	while(left < right)
	{
		cout << "enter external while ... " << left << " " << right << endl;
		int mid = left + (right-left)/2;
		if (A[mid] > data)
		{
			right = mid;
		}
		else if (A[mid] < data)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;//保证我当前的查找子数组中包含我要查找的元素
			cout << "enter internal while ... " << left << " " << right << endl;
			int temp = mid;
			while(left < right)
			{
				mid = left + (right-left)/2;
				cout << mid << " " << A[mid] << endl;
				if (A[mid] == data)
				{
					right = mid;
					temp = mid;
				}
				else
				{
					left = mid + 1;
				}
			}
			cout << "out " << mid << " " << A[mid] << endl;
			if (left >= right ) 
			{
				return temp;
			}
		}
	}
	return -1;
}


int main()
{
	int A[] = {1,1,2,4};
	int len = sizeof(A)/sizeof(int);
	int k = 4;
	int ret;
	ret = binarySearch(A,k,0,len);
	cout << k <<" occcur at " << ret << " position" << endl;
}
