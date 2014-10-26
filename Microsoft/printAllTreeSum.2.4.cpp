#include<iostream>
#include<iterator>
#include<vector>
#include "Build_Tree.h"

using namespace std;

int main()
{
	int vals = {10,5,12,4,7};
	TreeNode *root = build_tree(vals);
	vector<int> path;
	int sum = 22;

	printAllTreeSum(root,path,sum);
}
