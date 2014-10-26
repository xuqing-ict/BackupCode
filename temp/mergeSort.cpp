#include<iostream>
using namespace std;

void mergeSort(int *array, int left, int right)
{	
	int middle;
	if (left < right)
	{
		middle = (left + right)/2;
		mergeSort(array,left,middle);
		mergeSort(array,middle,right);
		merge(array,left,middle,right);
	}
}
void merge(int *array,int left, int middle, int right)
{
	for(int i=0,j=0,k=left; k < right;k++)
	{
		if (array[i] < array[j+right])
		{
			swap(array[])
		}

	}
}
int main()
{
	int array[] = {1,3,4,2};	
}
