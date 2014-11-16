  #include <bits/stdc++.h>
using namespace std;

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
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m >=n ) return head;
        ListNode dummy(-1);
        dummy.next = head;
        head = &dummy;

        while(--m) { head=head->next; if(head == nullptr ) return nullptr;}
        ListNode *L = head;
        ListNode *revHead = head->next;
        head->next = nullptr;

        int len = n-m;
        head=revHead;

        while(len--){head=head->next;if(head == nullptr) return nullptr;}

        ListNode *R = head->next;
        head->next = nullptr;
        revHead=reverse(revHead);

        L->next=revHead;
        while(revHead->next) revHead=revHead->next;
        revHead->next=R;
        return dummy.next;

    }
    int main()
    {
        ListNode *root= new ListNode(3);

        reverseBetween(head,1,2);
    }
