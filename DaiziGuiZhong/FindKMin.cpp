#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

vector<int> findKMin2Arr(vector<int> &A, vector<int> &B, const int K)
{
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	//pair (current sum, current index of B)
	priority_queue< pair<int, int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;
	vector<int> ret;
	for(int i = 0 ; i < K ; ++i)
	{
		pq.push(make_pair( A[i] + B[0], 0));
	}
	for(int i = 0 ; i < K ; ++i)
	{
		pair<int, int> cur = pq.top();
		ret.push_back(cur.first);
		pq.pop();
		
		cur.first += ( - B[cur.second] + B[cur.second + 1]);
		pq.push(cur);
		++cur.second;
	}
	return ret;
}

vector<int> findKMinKArr(vector<vector<int > > &A, int K)
{
	vector<int> ret;
	for(int i = 0;  i < K ; ++i )
	{
		sort(A[i].begin(), A[i].end());
	}

	for(int i = 0 ; i < K ; ++i)
	{
		copy(A[i].begin(), A[i].end(), ostream_iterator<int>(cout,"\t"));
		cout << endl;
	}
	vector<int>  temp = A[0];

	for(int i = 0 ; i < K-1 ; ++i)
	{
		cout << i << endl;
		ret = findKMin2Arr(temp, A[i+1], K);
		temp = ret;
	}
	return ret;
	
}
int main()
{
	const int K = 5;
	int data1[] = {5,3,4,1,2};
	int data2[] = {7,8,9,0,6};
	vector<int> A(data1, data1+K);
	vector<int> B(data2, data2+K);

	vector<int> ret = findKMin2Arr(A, B , K);
	for(int i = 0 ; i < ret.size() ; ++i)
	{
		cout << ret[i] << " " ;
	}
	cout << endl;

	vector<vector<int> > Ma;
	Ma.push_back(A);
	Ma.push_back(B);
	Ma.push_back(B);
	Ma.push_back(A);
	Ma.push_back(A);

	ret = findKMinKArr(Ma, K);
	for(int i = 0 ; i < ret.size() ; ++i)
	{
		cout << ret[i] << " " ;
	}
	

	return 0;
}
