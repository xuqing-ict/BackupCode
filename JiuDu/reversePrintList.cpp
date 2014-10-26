//输入一个链表，从尾到头打印链表每个节点的值。
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
void reversePrintList(ListNode *head)
{/*
    if(head == NULL) return;
    reversePrintList(head->next);
    cout << head->val << endl;
    return;*/
    stack<int> s;
    while(head)
    {
        s.push(head->val);
        head = head->next;
    }
    while(!s.empty())
    {
        //cout << s.top() << endl;
        printf("%d\n",s.top());
        s.pop();
    }
    return;
}
void destoryList(ListNode * &head)
{
    while(head)
    {
        ListNode *temp =  head->next;
        delete head;
        head = NULL;
        head = temp;
    }
    return;
}
ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *ret = reverseList(head->next);
    ListNode *tmp = ret;
    while(tmp->next) tmp=tmp->next;
    head->next = nullptr;  //必须加上这一句！！
    tmp->next = head;
    return ret;
}
void printList(ListNode *head)
{
    while(head)
    {
        cout <<head->val << "\t";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int number;
    ListNode *head = NULL, *temp = NULL;
    while(scanf("%d",&number)!= EOF)
    {
        if(number == -1) break;
        ListNode *node = new ListNode(number);
        if(head == NULL) {head = node; temp = node;}
        else {temp->next = node;temp = node;}
    }
    reversePrintList(head);
    head = reverseList(head);
    printList(head);
    destoryList(head);
    return 0;
}
