//单调队列
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<stack>
using namespace std;

void print(int A[], int len)
{
	for(int i = 0; i < len ; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int maxRecInHis(int height[], int len)
{
	if(len == 0) return 0;
        
        int *left = new int[len];
        stack<int> st;
        int maxi = 0;
        st.push(0);
        left[0] = 0;
        for(int i = 1 ; i < len ; ++i)
        {
            if(height[i] < height[st.top()])
            {
                while( (!st.empty()) && (height[i] < height[st.top()]) )
                {
                    left[i] = left[st.top()];
                    maxi = max(maxi, (i-left[st.top()])*height[st.top()]);
                    st.pop();
                }
                st.push(i);
            }
            else
            {
                left[i] = i;
                st.push(i);
            }
        }
        while(!st.empty())
        {
            maxi = max(maxi, (len-left[st.top()])*height[st.top()]);
            st.pop();
        }
        delete [] left;
        return maxi;
}


int main()
{
	int A[] = {2,1,5,6,2,3};
	int len = sizeof(A)/sizeof(int);
	cout << "max area = " << maxRecInHis(A,len);
}
