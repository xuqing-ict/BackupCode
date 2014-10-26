#include<iostream>
#include<ctime>
#include<cstdlib>
#include<assert.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void change(ListNode *head)
{
	ListNode * p = head;
	p->next->val = 0;
	p->next->next->val = 0;
}
int main()
{	

	int len = 3;
	int data[] = {6,5,7};
	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;

	for(int i = 1; i < len; ++i)
	{
		ListNode *node1 = new ListNode(data[i]);
		p->next = node1;
		p = node1;
	}
	p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	change(head);

	p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}

}
