#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
   ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    int Len(ListNode *head)
    {
        int ret=0;
        while(head)
        {
            ++ret;
            head=head->next;
        }
        return ret;
    }
    TreeNode *helper(ListNode *head, int len)
    {
        if(head == nullptr || len <= 0 ) return nullptr;

        ListNode *cur=head;
        int mid = (len+1)/2-1;
        int tmp = mid;
        while(tmp)
        {
            cur=cur->next;
            --tmp;
        }
        cout << "create root : " << cur->val << endl;

        TreeNode *root = new TreeNode(cur->val);
        root->left = helper(head,mid);
        root->right = helper(cur->next,len-mid-1);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        const int n = Len(head);
        cout << "n = " << n << endl;
        TreeNode *root=helper(head,n);
        return root;
    }

void destory(ListNode * &head)
{
    ListNode *tmp=nullptr;
    while(head)
    {
        tmp=head->next;
        delete head;
        head = nullptr ; //删除指针的额安全的方式，便是delete之后将该指针赋值为空
        head=tmp;
    }
    head = nullptr; //当然，头结点也不例外，如果传入的参数不是指针的指针或者是引用的话，那么head虽然delete掉了，但是该指针在下一次被赋值之前依然指向内存的某一块区域。
}

    int main(void)
    {
        ListNode *head = new ListNode(0);
        TreeNode *root = sortedListToBST(head);
        delete head;
        delete root;
        return 0;
    }
