//[left, right] is the range!!!! so while(elft <= right)!!!!!





#include<iostream>
using namespace std;

int binarySearch(int A[], int left, int right, int target)
{
	while(left < right)
	{
		int mid = left + (right - left)/2;
		cout << "external while : " << left <<" " << right << " " << mid << endl; 
		if (A[mid] < target)
		{
			left = mid + 1;
		}
		else if (A[mid] > target)
		{
			right = mid - 1;
		}
		// find it 
		else
		{
			int temp = mid;
			right = mid;
			while(left < right)
			{
				cout << "internal while : " << left <<" " << right << " " << mid << endl; 
				mid = left + (right - left)/2;
				if (A[mid] < target)
				{
					left = mid + 1;
				}
				else if (A[mid] > target)
				{
					cout << "NEVER" << endl;
				}
				else
				{
					right = mid;
					temp = mid;
				}
			}
			if(left <= right)
			{
				return temp;
			}
		}
	}
	return -1;
}


int main()
{
	int A[] = {0,1,2,2};
	int len = sizeof(A)/sizeof(int);
	cout << binarySearch(A,0,len,2) << endl;
}
