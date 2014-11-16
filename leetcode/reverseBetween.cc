#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

    ListNode *reverse(ListNode *head)
    {
        ListNode dummy(0);
        while(head)
        {
            ListNode *tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
       //illegal input
       if(head == NULL || m >= n || m <= 0)return head;
       ListNode dummy(0);
       dummy.next = head;
       head = &dummy;
       int t = m;
       ListNode *tempPre = head;
       while(t)
       {
           tempPre = head;
           head = head->next;
           --t;
       }

       ListNode *revHead = tempPre->next, *tmp = revHead;
       tempPre->next = nullptr;
       t = n-m;
       while(t--)tmp = tmp->next;
       assert(tmp);
       ListNode *right = tmp->next;
       assert(tmp);
       tmp->next = nullptr;
       revHead = reverse(revHead);

       tempPre->next = revHead;
       while(revHead->next) revHead = revHead->next;
       revHead->next = right;
       return dummy.next;
    }
    int main(void)
    {
        ListNode *head = new ListNode(3);
        head->next = new ListNode(5);

        head=reverseBetween(head,1,2);
        while(head)
        {
            cout <<head->val <<"\t";
            head=head->next;
        }
        return 0;
    }
