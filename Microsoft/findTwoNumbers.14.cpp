//在一个有序数组中找到两个数的和为sum
//如果要找到多个这样的数对。怎么办？
//本程序中使用的是在找到这样的一个数对之后l++／r--.
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

void findSumTwoNumber(vector<int> &numbers, int l , int r, int sum)
{
//	int n = numbers.size();
//	int l = 0, r = n-1;
	while(l < r)
	{
		if(numbers[l] + numbers[r] == sum)
		{
			cout << numbers[l] << " " << numbers[r] << endl;
			++l;
			//return;
			//findSumTwoNumber(numbers,(l+1),r,sum);
			//findSumTwoNumber(numbers, l,(r-1), sum);
			//return;
		}
		else if (numbers[l] + numbers[r] > sum)
			r--;
		else
			l++;
	}
	cout << "NO pair sum = " << sum << endl;
	return;
}

void merge(vector<int> &numbers, int l , int mid, int r)
{
//	cout << "merge ..." << l << " " << mid << " " << r << endl; 
	int lLen = mid-l+1;
	int rLen = r-mid;
	int *L = new int[lLen];
	int *R = new int[rLen];
	int lIndex = 0, rIndex = 0;
	while(lIndex < lLen){ L[lIndex] = numbers[lIndex + l];lIndex++;}
	while(rIndex < rLen){ R[rIndex] = numbers[mid+1+rIndex];rIndex++;}
	int index = l;
	lIndex = rIndex = 0;
	while(lIndex < lLen && rIndex < rLen)
	{
		if (L[lIndex] < R[rIndex])
		{
			numbers[index] = L[lIndex];
			index++; lIndex++;
		}
		else
		{
			numbers[index] = R[rIndex];
			index++;
			rIndex++;
		}
	}
	while(lIndex < lLen) {numbers[index] = L[lIndex];index++;lIndex++;}
	while(rIndex < rLen) {numbers[index] = R[rIndex];index++;rIndex++;}
	delete [] L;
	delete [] R;

}


void mergeSort(vector<int> &numbers, int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = l + (r-l)/2;
		cout << l << " " << r << " mid = " << mid << endl;
		mergeSort(numbers, l, mid);
		mergeSort(numbers , mid+1, r);
		merge(numbers,l,mid,r);
	}
}


int main()
{
	vector<int> numbers;
	/*
	int n = 0;
	cin >> n;
	int temp;
	while(n--)
	{
		cin >> temp;
		numbers.push_back(temp);
	}
	*/
	int num[] = {1,2,3,4,5,6,7};
	int n = sizeof(num)/sizeof(int);
	for(int i = 0 ; i < n; ++i)
		numbers.push_back(num[i]);
	cout << "numbers.size() = " << numbers.size() << endl;
	cout << "find sum = ";
	int sum = 8;
//	cin >> sum ;

	mergeSort(numbers,0,n-1);
	cout << "sort after: ";
	for(size_t i = 0;i < numbers.size();++i)
		cout << numbers[i] << " ";
	cout << endl;
	findSumTwoNumber(numbers,0,n-1,sum);

	return EXIT_SUCCESS;

}
