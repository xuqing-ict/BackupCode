
#include <iostream>
#include <stack>

#include <assert.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

    int sumNumbers(TreeNode *root) 
    {
        if(root == NULL ) return 0;
        
        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        int temp = 0;
        int ret = 0;
        
        while(root || ( !s.empty() ) )
        {
            while(root)
            {
				cout << "push" << root->val << endl;
                s.push(root);
                temp = temp*10;
                temp = temp + (root->val);
                root = root->left;
            }
			assert(!s.empty());
            root = s.top();
			
			cout << "pop1" << root->val << " temp = " << temp << endl;
            if(root->right == NULL || pre == root->right)
            {
				cout << "pop2" << root->val << " temp = " << temp << endl;
                if(root->right == NULL) 
                {
					cout << "pop3" << root->val << " temp = " << temp << endl;
                    ret += temp;
                }
                s.pop();
                temp = temp/10;
                pre = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
        return ret;
    }

int main()
{
	TreeNode *root = new TreeNode(0);
	cout << sumNumbers(root) << endl;
	delete root;
	return 0;
}
