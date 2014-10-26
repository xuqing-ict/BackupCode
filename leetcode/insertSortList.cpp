#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
using namespace std;
//const int MIN = INT_MIN;
const int MIN = -1;


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};


void printList(ListNode *head)
{
	if(head == NULL) cout <<"head null." << endl;
	ListNode *p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

}

//delete list must transfer the reference or **
void deleteList(ListNode * & head)
{
	if (head == NULL)
		return;
	ListNode *p = head;
	ListNode *t = head;
	while(p->next)
	{
		t = p->next;
		delete p;
        p = t;
	}
	delete p;
	head = NULL;
}


ListNode *sortList(ListNode *head)
{
	if (head == NULL)
	{
		return head;
	}

	ListNode *Head = new ListNode(MIN);
	Head->next = head;
	printList(Head);
	ListNode *cur = Head;

	ListNode *t = NULL;
	ListNode *t2 = NULL;
	ListNode *t3 = NULL;
	ListNode *t4 = NULL;

	while(cur->next)
	{
		cout << "current val = " << cur->next->val << endl;
		printList(Head);

		t = Head;
		t2 = cur->next;

		while(((t->next) != t2) && ((t->next)->val) <= t2->val) //保证当前的比较一定会在本节点处终止
			t = t->next;

		if (t->next == t2)
		{
			cout << " == t->next->val = " << t->next->val << " " << " t2->val = " << t2->val << endl; 
			cur = cur->next;
			continue;
		}
		else
		{
			cout << "t->next->val = " << t->next->val << " " << " t2->val = " << t2->val << endl; 

			t4 = cur->next;
			cout << "t4 = " << t4->val << endl;
			cur->next = t2->next;
			t3 = t->next;
			cout << "t3->val = " << t2->val << endl;
			t->next = t2;
			t2->next = t3;
			cur = t4;//备份cur的值。
		}
	}
	cout << "!!!" << endl;
	head = Head->next;
	printList(Head);
	delete Head;
	Head = NULL;
	return head;

}


int main()
{
	srand(time(NULL));
	int len  = rand() % 20;
	ListNode * head = NULL;
	ListNode * p = NULL;
	ListNode * node = NULL;

	for(int i = 0;i < len; ++i)
	{
		if (head == NULL)
		{
			head = new ListNode(rand()%20);
			p = head;
			continue;
		}
		else
		{
			node = new ListNode(rand()%20);
			p->next = node;
			p = node;
		}
	}
	printList(head);
	cout << "!!!" << endl;
	head = sortList(head);
	cout << "after sort..." << endl;
	printList(head);
	deleteList(head);

}
