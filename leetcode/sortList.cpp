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

void merge(ListNode *&head, ListNode *L, ListNode *R)
{
	ListNode *t = NULL;
	ListNode *p = NULL;
	head = NULL;

	p = L;cout << "L = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;
	p = R;cout << "R = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;
	if (L->val > R->val)
	{
		t = L;
		L = R;
		R = t;
	}
	p = L;cout << "L = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;
	p = R;cout << "R = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;
	ListNode *tempL = L; 
	ListNode *tempR = R;
	ListNode *tHead = head;

	while(tempL && tempR )
	{
		cout << "while " << tempL->val << " " << tempR->val << endl;
		if (tempL->val > tempR->val)
		{
			cout << tempL->val << " >= " << tempR->val << endl; 
			if (tHead == NULL) 
			{
				tHead = tempR;
				head = tempR;
			}
			else
			{
				tHead->next = tempR;
				tHead = tHead->next;
			}
			tempR = tempR->next;
		}
		else
		{
			cout << tempL->val << " < " << tempR->val << endl; 
			if (tHead == NULL) 
			{
				tHead = tempL;
				head = tempL;
			}
			else
			{
				tHead->next = tempL;
				tHead = tHead->next;
			}
			tempL = tempL->next;
		}
	}
	
	assert(tempL == NULL||tempR == NULL);

	if (tempR != NULL)
	{			
		if (tHead == NULL) 
		{
			tHead = tempR;
			head = tempR;
		}
		tHead->next = tempR;
	}
	if (tempL != NULL)
	{			
		if (tHead == NULL) 
		{
			tHead = tempL;
			head = tempL;
		}
		tHead->next = tempL;
	}
}



ListNode *sortList(ListNode * head) 
{
	if (head== NULL || head->next == NULL)
	{
		return head;
	}
	cout << "sortList... ";
	ListNode *p = head;while(p){cout << p->val << " ";p = p->next;}cout << endl;

	ListNode *R = head;
	ListNode *L = head;
	ListNode *temp = head;
	
	ListNode *fast = head->next;
	ListNode *slow = head;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	L = head;
	R = slow->next;

	//split the L and R
	slow->next = NULL;
	


/*
	int i = 0;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	i = (i-1)/2;
	while( i > 0 )
	{
		R = R->next;
		i--;
	}
	ListNode *mid = R;
	R = R->next;
	mid->next = NULL;
*/

	//if ( L ->next != R)
	//{
		p = L;cout << "L = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;
		p = R;cout << "R = ";while(p){cout << p->val << " ";p = p->next;}cout << endl;

		L = sortList(L);
		R = sortList(R);
		merge(head,L,R);
		cout<< "head = "; p = head;while(p){cout << p->val << " ";p = p->next;}cout << endl;
	//}

	return head;	        
}

ListNode *deleteList(ListNode *head)
{
	ListNode *t = head;
	ListNode *s = NULL;
	while(t)
	{
		s = t->next;
		delete t;
		t = s;
	}
	return NULL;
}


int main()
{	
	srand(time(NULL));
	int len = rand()%10;
	int *data = new int[len];
	for(int i = 0 ; i < len ; ++i)
		data[i] = rand()%10;
	for(int i = 0 ; i < len ; ++i)
		cout << data[i] << " ";
	cout << endl;

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

	head = sortList(head);

	p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}

	head = deleteList(head);

}
