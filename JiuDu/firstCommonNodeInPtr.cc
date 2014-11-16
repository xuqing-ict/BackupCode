#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val):val(_val),next(nullptr){}
};

int length(ListNode *head)
{
    int ret=0;
    while(head)
    {
        ret++;
        head=head->next;
    }
    return ret;
}

ListNode *CommonNode(ListNode *head1, ListNode *head2)
{
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    int len1=length(head1);
    int len2=length(head2);
    if(len1>len2)
    {
        int prev = len1-len2;
        while(prev--)head1=head1->next;
    }
    else
    {
        int prev=len2-len1;
        while(prev--)head2=head2->next;
    }
    while(head1 && head2 && head1!=head2)
    {
        head1=head1->next;
        head2=head2->next;
    }
    if(head1 == head2 && head1) return head1;
    return nullptr;
}

ListNode *createList(int *A, int len)
{
    ListNode dummy(0), *ret=&dummy;

    if(A == nullptr || len <= 0) return nullptr;
    for(int i=0;i<len;++i)
    {
        ListNode *node =  new ListNode(A[i]);
        ret->next=node;
        ret=node;
    }
    return dummy.next;
}

int main(void)
{
    int len1,len2;
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;

    while(scanf("%d\t%d",&len1,&len2)!=EOF)
    {
        int tmp;
        int *A = new int[len1];
        int *B = new int[len2];
        for(int i=0;i<len1;++i)
            scanf("%d",&A[i]);
         for(int i=0;i<len2;++i)
            scanf("%d",&B[i]);
        head1 = createList(A,len1);
        head2 = createList(B,len2);
        delete [] A;
        delete [] B;
        ListNode *ret = CommonNode(head1,head2);
        if(ret) cout << ret->val<< endl;
        else cout << "My God" << endl;
    }
    return 0;
}
