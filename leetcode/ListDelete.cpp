#include <iostream>
#include <limits.h>

using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode *deleteDuplicates(ListNode *head) {
	ListNode *dummy = new ListNode(INT_MIN);
	ListNode *tmp = dummy;
	ListNode *cur = NULL;
	while(head)
	{
		if(head->next && head->next->val == head->val)
		{
			while(head->next && head->next->val == head->val)
			{
				cur  = head->next;
				delete head;
				head = cur;
			}
			head = head->next;
			delete cur;
		}
		else
		{
			tmp->next = head;
			head = head->next;
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	tmp = dummy->next;
	delete dummy;
	return tmp;

}
ListNode *deleteDuplicates2(ListNode *head) {
	if(head == NULL)return head;
	ListNode *fast = head->next;
	ListNode *slow = head;
	ListNode *cur = NULL;

	while(fast)
	{
		while(fast && fast->val == slow->val) 
		{
			cur = fast->next;
			delete fast;
			fast = cur;
		}
		slow->next = fast;
		slow = fast;
		//if the slow is not NULL
		if(slow)
		{
			fast = slow->next;
		}
	}
	return head;
}
void createList(ListNode *&head, int A[], int n)
{
	ListNode *temp = NULL;
	for(int i = 0 ; i < n ; ++i)
	{
		ListNode *node = new ListNode(A[i]);
		if (head == NULL)
		{
			head = node;
			temp = head;
		}
		else
		{
			temp->next = node;
			temp = temp->next;
		}
	}
	return ;

}


void deleteList(ListNode *head)
{
	if(head == NULL)
	{
		return;
	}
	ListNode *temp = NULL;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	return;
}

void printList(ListNode *head)
{
	if(head == NULL)
	{
		return ;
	}
	while(head)
	{
		cout << head->val << " "; 
		head = head->next;
	}
	cout << "\n"; 
	return;

}
int main()
{

	ListNode *head = NULL;
	int A[] = {1,2,3,4,4,5,6};
	int n = sizeof(A)/sizeof(int);
	createList(head, A, n);
	printList(head);
	//deleteDuplicates(head);
	deleteDuplicates2(head);
	printList(head);
	deleteList(head);
}
