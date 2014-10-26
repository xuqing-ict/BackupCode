#include <iostream>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node(int x):val(x),left(NULL),right(NULL){}
};


int main()
{
	node root(1);
	node node2(2);
	node node3(3);
	node node4(4);

	preTraverse(root);
	return 0;

}
