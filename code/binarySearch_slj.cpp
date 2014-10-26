#include<iostream>
using namespace std;

int binarySearch(int A[], int data, int left, int right)
{
	while(left < right)
	{
		cout << "enter external while ... " << left << " " << right << endl;
		int mid = left + (right-left)/2, mid_tmp;
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
			right = mid;
			cout << "enter internal while ... " << left << " " << right << endl;
			while(left < right)
			{
				mid_tmp = left + (right-left)/2;
				cout << mid << " " << A[mid] << endl;
				if (A[mid_tmp] == data)
				{
					right = mid_tmp;
					mid = mid_tmp;
				}
				else
				{
					left = mid_tmp + 1;
				}
			}
			cout << "out " << mid << " " << A[mid] << endl;
			return mid;
			/*
			if ((left >= right) && (A[mid] == data)) 
			{
				return mid;
			}
			else
			{
				return -1;
			}*/
		}
		if (left >= right)
		{
			return (A[mid] == data)? mid :(-1);
		}
	}
}


int main()
{
	int A[] = {1,2,2,2,3};
	int len = sizeof(A)/sizeof(int);
	int k = 2;
	int ret;
	ret = binarySearch(A,k,0,len);
	cout << k <<" occcur at " << ret << " position" << endl;
}
