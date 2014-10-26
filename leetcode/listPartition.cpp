//注意新的链表的表尾的元素一定是指向空的！！！
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>

using namespace std;
const int MIN = INT_MIN;


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


void deleteList(ListNode *head)
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

ListNode *listPartition(ListNode *head, int x)
{
	cout << "partition list, x = " << x << endl;
	ListNode *tHead = head;
	
	ListNode *less = NULL;
	ListNode *grt = NULL;
	ListNode *lessHead = NULL;
	ListNode *grtHead = NULL;

	ListNode *temp = NULL;
	
	while(tHead)
	{
		cout << "current = " << tHead->val << endl;
		if (tHead->val < x)
		{
			if (lessHead == NULL)
			{
				temp = tHead->next;
				lessHead = tHead;
				less = tHead;
				less->next = NULL;
			}
			else
			{
				temp = tHead->next;
				tHead->next = NULL;
				less->next = tHead;
				less = less->next;
			}
			tHead = temp;
		}
		else
		{
			if (grtHead == NULL) 
			{
				temp = tHead->next;
				grtHead = tHead;
				grt = tHead;
				grt->next = NULL;
			}
			else
			{
				temp = tHead->next;
				tHead->next = NULL;
				grt->next = tHead;
				grt = grt->next;
			}
			tHead = temp;
		}
		cout << "L = :";
		printList(lessHead);
		cout << "R = :";
		printList(grtHead);
	}
	cout << "L = :";
	printList(lessHead);
	cout << "R = :";
	printList(grtHead);

	if (lessHead == NULL)
	{
		return grtHead;
	}

	tHead = lessHead;
	temp = lessHead;
	while(tHead)
	{
		temp = tHead;
		tHead = tHead->next;
	}
	temp->next = grtHead;
	cout << "merge..." << endl;
	printList(lessHead);

	return lessHead;


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
	head = listPartition(head,rand()%20);
	printList(head);
	deleteList(head);

}
