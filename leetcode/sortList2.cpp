#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

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


/*

ListNode *merge(ListNode *L, ListNode *R)
{
	ListNode *tL = L;
	ListNode *tR = R;
	ListNode *head = NULL;
	ListNode *curPtr = NULL;
	while(tL && tR)
	{
		if (tL->val <= tR->val)
		{
			if (head == NULL)
			{
				head = tL;
				curPtr = head;
			}
			else
			{
				curPtr->next = tL;
				curPtr = curPtr->next;
			}
			tL = tL->next;
		}
		else
		{
			if (head == NULL)
			{
				head = tR;
				curPtr = head;
			}
			else
			{
				curPtr->next = tR;
				curPtr = curPtr->next;
			}
			tR = tR->next;
		}
	}
	if (tL != NULL)
	{
		if (head == NULL)
		{
			head = tL;
		}
		else
		{
			curPtr -> next = tL;
		}
	}
	if (tR != NULL)
	{
		if (head == NULL)
		{
			head = tR;
		}
		else
		{
			curPtr ->next = tR;
		}
	}
	return head;
}
*/

ListNode *merge(ListNode *L, ListNode *R)
{
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	ListNode *tL = L;
	ListNode *tR = R;
	while(tL && tR)
	{
		if (tL->val <= tR->val)
		{
			cur->next = tL;
			tL = tL->next;
			cur = cur->next;
		}
		else
		{
			cur->next = tR;
			tR = tR->next;
			cur = cur->next;
		}
	}
	cur->next = (tL != NULL)?tL:tR;
	cur = head->next;
	delete head;

	return cur;
}





ListNode *sortList(ListNode *head)
{
	//partition
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *L = head;
	ListNode *R = NULL;
	ListNode *fast = head->next;
	ListNode *slow = head;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	R = slow->next;
	slow->next = NULL;
	cout << "L = ";
	printList(L);
	cout << "R = ";
	printList(R);
	sortList(L);
	sortList(R);
	head = merge(L,R);
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
	head = sortList(head);
	printList(head);
	deleteList(head);

}
