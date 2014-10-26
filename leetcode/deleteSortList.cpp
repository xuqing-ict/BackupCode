//删除单链表中的重复元素
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *deleteDuplicates(ListNode *head) {
	if(head == NULL || head->next == NULL)return head;
	ListNode *p = head->next;
	ListNode *q = p->next;
	while(q)
	{
		while(q && q->val == p->val) q = q->next;
		p->next = q;
		p = q;
	}
	return head;
}

void printList(ListNode *head)
{
	if (head->next == NULL)cout << "empty list..." << endl;
	ListNode *p = head->next;
	while(p){cout << p->val << " ";p=p->next;}
	cout << endl;
} 
int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(1);
	p1->next = p2;
	p2->next = p3;
	//ListNode *head = new ListNode(0);
	//head->next = p1;
	ListNode *head = p1;
	cout << "delte before ";
	printList(head);
	deleteDuplicates(head);
	cout << "delte after ";
	printList(head);
	delete p1;
	delete p2;
	delete p3;
	return 0;

}
