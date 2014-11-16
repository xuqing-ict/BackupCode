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
        head = nullptr ; //ɾ��ָ��Ķȫ�ķ�ʽ������delete֮�󽫸�ָ�븳ֵΪ��
        head=tmp;
    }
    head = nullptr; //��Ȼ��ͷ���Ҳ�����⣬�������Ĳ�������ָ���ָ����������õĻ�����ôhead��Ȼdelete���ˣ����Ǹ�ָ������һ�α���ֵ֮ǰ��Ȼָ���ڴ��ĳһ������
}

    int main(void)
    {
        ListNode *head = new ListNode(0);
        TreeNode *root = sortedListToBST(head);
        delete head;
        delete root;
        return 0;
    }
