//单调队列！！！
//单调队列允许队尾插入与删除，队首只允许删除。
//单调队列的队头一定是当前队列中的最大值
//每一次加入元素时，首先去掉队头的过期的元素，再将当前元素插入，
//插入当前元素时，由于此时队列中的元素都不是过期的元素，于是将元素插入时，依次与队尾进行比较，如果大于队尾，将队尾删除，直到找到一个大于当前元素的位置或者队列为空时终止，插入该元素。
//返回队首即可
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAX = 100;

static int head = 0; // the first element of queue
static int tail = 0; // the last position to add elem
static int K = 3;

int queue[MAX]; // store index

int FindMax(int A[], int B[], int len)
{
	for(int index = 0; index < len; ++index)
	{
		cout << "index = " << index << endl;
		if (head == tail) //no elem in queue
		{
			queue[tail++] = index;
			cout << "empty " << B[index] << endl; 
			B[index] =  A[queue[head]];
			for(int i = head ;i < tail; ++i)
				cout << A[queue[i]] << " ";
			cout << endl;
		}
		else if (head < tail)
		{
			while( (head < tail) && (queue[head] <= ( index-K))) head++;
			if (head == tail)
			{
				queue[tail++] = index;
				B[index] = A[queue[head]];
				cout << "delete empty " << B[index] << endl;
				for(int i = head ;i < tail; ++i)
					cout << A[queue[i]] << " ";
				cout << endl;
				continue;
			}
			while((head < tail) && (A[queue[tail-1]] < A[index])) --tail;
			queue[tail++] = index;
			for(int i = head ;i < tail; ++i)
				cout << A[queue[i]] << " ";
			cout << endl;
			B[index] =  A[queue[head]];
			cout << "output tail "  << B[index]<< endl;
		}
	}
}
int main()
{
	srand(time(NULL));
	int len = rand()%20;
	int *A = new int[len];
	for(int i = 0;i < len; ++i)
		A[i] = rand()%20;
	//int len = 8;
	//int A[]= {11,10,19,5,17,7,9,7};
	int *B = new int[len];  //记录数组的当前3个元素（包括自身）的最小值。
	for(int i = 0 ;i < len; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	FindMax(A,B,len);
	for(int i = 0 ;i < len; ++i)
	{
		cout << B[i] << " ";
	}
	cout << endl;
}
