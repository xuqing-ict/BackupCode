#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode *build_tree(vactor<int> vals)
{

	for(int i = 0 ;i < vals.size(); ++i)
	{
		if (vals[i] == -1)
		{
			continue;
		}

	}
}



