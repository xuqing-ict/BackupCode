/**
 * @file reverseLinkList.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-28
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void print(ListNode*);
inline int length(ListNode *head)
{
    int result = 0;
    while(head)
    {
        head = head->next;
        ++result;
    }
    return result;
}

void print(ListNode *head) 
{
    ListNode *temp = head;
    while(temp)
    {
        cout << temp->val<< " ";
        temp =  temp->next;
    }
    cout << endl;
}
void destory(ListNode * &head)
{
    while(head)
    {
        ListNode *tmp = head->next;
        delete head;
        head = nullptr;
        head = tmp;
    }
}
ListNode *reverse(ListNode *head)
{
    ListNode dummy(0);
    ListNode *ret = &dummy;
    while(head)
    {
        ListNode *tmp = head->next;

        head->next = ret->next;
        ret->next = head;

        head = tmp;
    }
    return ret->next;
}
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m >=n ) return head;

    ListNode dummy(-1);
    dummy.next = head;
    head = &dummy;
    int tmp = m;
    while(--tmp) { head=head->next; if(head == nullptr ) return nullptr;}
    ListNode *L = head;
    ListNode *revHead = head->next;
    head->next = nullptr;
    cout << L->val << endl;
    cout << revHead->val << endl;
    
    int len = n-m;
    head=revHead;
    cout << "len : " << len << endl;
    while(len--)
    {
        cout << "len : " << len << endl;
        assert(head);
        head=head->next;
    }

    if(head)cout << head->val << endl;

    ListNode *R;
    if(head==nullptr) R = nullptr;
    else {R=head->next;head->next=nullptr;}
    print(revHead);
    revHead=reverse(revHead);
    print(revHead);
    L->next=revHead;
    while(revHead->next) revHead=revHead->next;
    revHead->next=R;
    return dummy.next;

}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    print(head);
    head = reverseBetween(head,2,3);
    print(head);

    /*
       ListNode *temp = head->next;
       temp->next = new ListNode(3);
       temp = temp->next;
       temp->next = new ListNode(4);
       temp = temp->next;
       temp->next = new ListNode(5);

       cout << length(head) << endl;
       print(head);
       ListNode *rev = reverseKGroup(head,4);
       print(rev);
          */
    destory(head);
    return 0;
}
