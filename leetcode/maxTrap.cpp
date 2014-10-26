#include<iostream>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;


int maxTrap(int A[],int len)
{
	/*
	queue<int> q;
	int area = 0;
	if(len == 0 )return 0;
	
	for(int i = 0; i < len ; ++i)
	{
		cout << "A[" << i << "] = " << A[i] << endl;
		if (q.empty())
		{
			cout << "ONLY" << endl;
			q.push(i);
			continue;
		}

		int left = A[q.front()];
		if (A[i] < left)
		{
			q.push(i);
		}
		else
		{
		
			int width = q.size();
			q.pop();
			int sum = 0;
			while(!q.empty())
			{
				sum += A[q.front()];
				q.pop();
			}
			cout << "\tleft = " << left << endl;
			cout << "\t\twidth = " << width << endl;
			area += left*(width-1);
			cout << "sum = 0 !!! " << sum << endl;
			area -= sum;
			assert(q.empty());
			cout << "\t\tarea = " << area << endl;
			q.push(i);
		}
	}
	return area;
}
*/
	stack<int> myStack;
	int area = 0;
	if(len == 0 )return 0;
	int index = 0 ;
	
	for(int i = 0; i < len ; ++i)
	{
		cout << "A[" << i << "] = " << A[i] << endl;
		
		if(myStack.empty()){myStack.push(i);continue;}
		if (A[myStack.top()] > A[i])
		{
			myStack.push(i);
			continue;
		}
		while( !(myStack.empty() ) && ( A[myStack.top()] <= A[i]) )
		{
			index = myStack.top();
			myStack.pop();
		}
		assert(myStack.empty() || A[myStack.top()] >= A[i]);

		area += ((i-index-1)*A[index]);
		cout << "area = "<< area << endl;
		for(int j = index+1 ; j < i; j++)
			area -= A[j];
		cout << index << " " << i << " area = " << area << endl;
		myStack.push(i);
	}
	
	return area;
}


int main()
{
	//int len = 5;
	//int data[] = {2,1,2,3,2};
	int len = 12;
	int data[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << "max = " << maxTrap(data,len) << endl;
	return 0;
}
