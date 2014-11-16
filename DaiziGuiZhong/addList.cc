#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val):val(_val),next(nullptr){}
};

void destory(ListNode * &head)
{
    if(head == nullptr) return;
    ListNode *tmp = nullptr;
    while(head)
    {
        tmp = head->next;
        delete head;
        head = nullptr;
        head = tmp;
    }
}

void print(ListNode *head)
{
    if(head == nullptr) return;
    while(head)
    {
        cout <<head->val << " ";
        head = head->next;
    }
    cout << endl;
}
//head1 and head2 have same length.
int len(ListNode *head)
{
    int len = 0;
    while(head){++len;head=head->next;}
    return len;
}
ListNode *helper(ListNode *lhs, ListNode *rhs, int &carry)
{
    if(lhs==nullptr && rhs == nullptr) return nullptr;
    ListNode *ret = helper(lhs->next,rhs->next,carry);
    int sum = lhs->val+rhs->val+carry;
    carry = sum/10;
    int a = sum-carry*10;
    ListNode *node = new ListNode(a);
    node->next = ret;
    ret = node;
    return ret;
}
ListNode *addList(ListNode *head1, ListNode *head2)
{
    int len1 = len(head1), len2 = len(head2);
    if(len1 != len2)
    {
        cout << "This function is not available the lists with different length..." <<endl;
        return nullptr;
    }
    int carry = 0;
    ListNode *ret = helper(head1,head2,carry);
    if(carry)
    {
        ListNode *node=new ListNode(1);
        node->next = ret;
        ret = node;
    }
    return ret;
}
int main(void)
{
    ListNode *head1 = new ListNode(9);
    //head1->next = new ListNode(9);
    ListNode *head2 = new ListNode(1);
    //head2->next = new ListNode(9);
    ListNode *ret = addList(head1,head2);
    print(head1);
    print(head2);
    print(ret);
    destory(head1);
    destory(head2);
    destory(ret);
    return 0;
}

