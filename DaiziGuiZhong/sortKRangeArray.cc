//sort the array which the difference between the index of the array and the index of the sorted array is less than k.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sorted(vector<int> &A, int k)
{
    const int n = A.size();
    if(k <= 0 || k > n || n < 2)
    {
       // cout <<  "Input k is illegal..." << endl;
        return;
    }
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i=0;k<k;++i) pq.push(A[i]);
    for(int i=k;i<n;++i)
    {
        A[0] = pq.top();pq.pop();
        pq.push(A[i]);
    }
    int i=0;
    while(!pq.empty()) { A[n-k-i] = pq.top();pq.pop();}
    return ;
}

int main(void)
{

    return 0;
}
