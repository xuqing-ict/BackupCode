#include <iostream>
#include <iterator>
using namespace std;

void CountSort(int data[], int length) 
{ 
	if(data == NULL || length <= 0) 
		return; 
	int maxData = 0; 
	for(int i = 0; i != length; ++i) 
		if(maxData < data[i]) 
			maxData = data[i]; 
	int *countArray = new int[maxData+1];
	for(int i = 0; i != length; ++i) 
		countArray[data[i]]++; 
	for(int i = 1; i <= maxData; ++i) 
		countArray[i] += countArray[i-1]; 
	int *newData = new int[length]; 
	for(int j = length-1; j >= 0; --j) 
	{ 
		newData[countArray[data[j]]] = data[j]; 
		countArray[data[j]]--; 
	} 
	for(int k = 0; k != length; ++k) 
		data[k] = newData[k]; 

	delete[] newData; 
	delete[] countArray; 
}
int main()
{
	int A[] = {0,1,3,4,2};
	copy(A,A+5,ostream_iterator<int>(cout,"\t"));
	CountSort(A,5);
	copy(A,A+5,ostream_iterator<int>(cout,"\t"));
	return 0;
}
