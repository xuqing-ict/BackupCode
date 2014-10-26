//所有元素出现3次，只有一个出现一次，找出这个出现一次的
//优先级问题 ？ ： << >>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAX = 100;


void printBinary(int val)
{
	unsigned int base = 1;
	unsigned int temp = sizeof(val)*8;
	while(val && (temp--))
	{
		cout << ((val & base)?1:0) << " ";
		val = val >> 1;
	}
	cout << endl;

}

int complementToInt(int val)
{
	unsigned int temp = sizeof(val)*8;
	unsigned int base = 1;
	if (val & (base<<(temp-1)))
	{
		cout << "imput invalid..." << endl;
	}
}



int findSingleNumber2(int A[], int len)
{
	unsigned int base = 1;
	unsigned int ret;
	int single = 0;
	unsigned int val = 0;

	int temp = sizeof(int)*8;
	while(temp--)
	{
		cout << "base  = " << base << " temp = " << temp  << " single = " << single << endl; 
		ret = 0;
		
		for(int j = 0 ; j < len ; j++)
			ret = ret + ((A[j]&base)?1:0); //每一步只需要记录0或者1！！！！并非结果值。
		cout << "ret = " << ret << endl;
		
		if (ret%3 != 0) single |= base;
		base = (base << 1);
	}
	cout << "single = " << single << endl;
	return single;
}




int main()
{
	int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	/*unsigned int base = 1;
	int val =  A[0];
	int temp = 32;
	while(val && (temp--))
	{
		cout << ((val & base)?1:0) << " ";
		val = val >> 1;
	}
	*/
	int len = sizeof(A)/sizeof(int);
	for(int i = 0; i < len ;++i)
		printBinary(A[i]);

	cout <<	"!!! = " << findSingleNumber2(A,len) << endl;

	return 0;
}
