#include<iostream>
using namespace std;
struct Node
{
	int x;
	int y;
};

double dis(Node node1, Node node2)
{
	return sqrt((node2.y-node1.y)*(node2.y-node1.y) + (node2.y-node1.y)*(node2.y-node1.y) )
}
int main()
{
	Node node[7] = {{1,7},{2,1},{3,4},{6,5},{7,2},{8,6},{9,3}};
	for(int i = 0;  i < 7 ;++i)
		cout << node[i].x << " " << node[i].y << endl;

	for(int i = 3 ;i < 7 ;++i)
	{

	}
	
	return 0;

}
