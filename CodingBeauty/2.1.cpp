#include<iostream>
#include<bitset>

#include<limits.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

using namespace std;


double interval;
clock_t start,end;

//然而除法与取余的时间较长
unsigned int count1(int number)
{
	unsigned int count = 0;
	while(number)
	{
		count +=number%2;
		number = number/2;
	}
	return count;
}


unsigned int count2(unsigned int number)
{
	unsigned int count = 0;
	while(number)
	{
		count += number&0x01;
		number >>= 1;
	}
	return count;
}

unsigned int count3(unsigned int number)
{
	unsigned int count = 0;
	while(number)
	{
		number = (number&(number-1));
		count++;
	}
	return count;
}

unsigned int diff(unsigned int A, unsigned int B)
{
	unsigned int C = A^B;
	return count3(C);
}



int main()
{
	unsigned int number = 66;
 	unsigned A = 74;
	unsigned B = 68;

	bitset<64> b1(number);
	bitset<64> a(A);
	bitset<64> b(B);
	cout << "b1 = " << b1 << endl;

	start = clock();

	cout << "i's number = " << count1(number) << endl;
	cout << "i's number = " << count2(number) << endl;
	cout << "i's number = " << count3(number) << endl;
	cout << a << "\n" << b << "\n" << " diff = " << diff(A,B) << endl;
	end = clock();

	interval = (double)(end-start);
	cout << "time : " << interval << endl;
}
