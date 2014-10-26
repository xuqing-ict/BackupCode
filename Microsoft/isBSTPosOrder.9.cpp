#include<iostream>
#include<vector>
using namespace std;

bool isBST(vector<int> nodes , int l , int r)
{
	if(l>=r)return true;
	int i = l;
	int left=0;
	while(i<r && nodes[i] < nodes[r])i++;
	left=i;
	int temp=l;
	cout << "L = ";
	while(temp < i) {cout << nodes[temp] << " ";temp++;}
	cout << endl;
	temp = left;
	cout << "R = ";
	while(i<r && nodes[i] > nodes[r])i++;
	while(temp < i) {cout << nodes[temp] << " ";temp++;}
	cout << endl;
	if(i!=r) return false;
	else
		return isBST(nodes,l,left-1) && isBST(nodes,left,r-1);
}

int main()
{
	vector<int> nodes;
	int data[] = {0,1};
	int n = sizeof(data)/sizeof(int);
	for(int i=0 ; i<n ; ++i)
	{
		nodes.push_back(data[i]);
	}
	if(isBST(nodes , 0, n-1))
	{
		cout << "is BST..." << endl;
	}
	else
	{
		cout << "is not BST..." << endl;
	}
}
