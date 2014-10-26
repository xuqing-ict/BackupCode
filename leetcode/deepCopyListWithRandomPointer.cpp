//deepCopy不能改变原来的链表！！！
//此问题的难点主要在于每一个节点都有一个random的指针指向链表中的其他元素。
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<assert.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode *randPtr;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deepCopy(ListNode *head)
{
	//copy
	ListNode *tHead = head;
	ListNode *next = NULL;
	while(tHead)
	{
		next = tHead->next;
		ListNode *node = new ListNode(tHead->val*10);
		node->next = tHead->next;
		//node->randPtr = tHead->randPtr;
		tHead->next = node;
		tHead = next;
	}
	cout << "merge" << endl;
	tHead = head;
	while(tHead)
	{
//		cout << p->val << " ";
		if (tHead->randPtr)
		{
			tHead->next->randPtr = tHead->randPtr->next;
		}
		tHead = tHead->next->next;
	}
	
	tHead = head;
	while(tHead)
	{
		if (tHead->randPtr)
			cout << "rand1: " << tHead->val << " --> "<< tHead->randPtr->val << endl;
		tHead = tHead->next;
	}
	
	




	cout << "after split" << endl;
	//split
	tHead = head;
	ListNode *newList = NULL;
	ListNode *temp = NULL;
	ListNode *next2=NULL;

	while(tHead)
	{
		//cout << p->val << " ";
		if (newList == NULL)
		{
			next2 = tHead->next->next;
			newList = tHead->next;
			temp = newList;
			tHead->next = next2;
			tHead = next2;

		}
		else
		{
			next2 = tHead->next->next;
			temp->next = tHead->next;
			tHead->next = next2;
			tHead = next2;
			temp = temp->next;
		}
	}
	cout << endl;
	
	tHead = newList;
	while(tHead)
	{
		//cout << p->val << " ";
		if (tHead->randPtr)
		{
			cout << "rand1: " << tHead->val << " --> "<< tHead->randPtr->val << endl;
		}
		tHead = tHead->next;
	}
	cout << "return..." << endl;



	return newList;
}

void deleteList(ListNode *head)
{
	ListNode *next = NULL;
	while(head)
	{
		next = head->next;
		delete head;
		head = next;
	}
}



int main()
{	
	srand(time(NULL));
	//int len = rand()%10;
	//int *data = new int[len];
	int len =1;
	int data[] = {-1};
	//for(int i = 0 ; i < len ; ++i)
		//data[i] = rand()%10;

	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;

	for(int i = 1; i < len; ++i)
	{
		ListNode *node1 = new ListNode(data[i]);
		p->next = node1;
		p = node1;
	}
	/*p = head;
	head->randPtr = head->next->next;
	head->next->randPtr = head->next->next->next;
	cout << "rand1: " << head->val << " --> " << head->randPtr->val << endl;
	cout << "rand2: " << head->next->val << " --> " << head->next->randPtr->val << endl;

*/


	p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	ListNode *head2 = NULL;
	head2 = deepCopy(head);
	
	cout << "pre: ";
	p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	p = head;
	while(p)
	{
		if (p->randPtr)
			cout << "rand1: " << p->val << " --> "<< p->randPtr->val << endl;
		p = p->next;
	}
	
	deleteList(head);
	cout << "now2: ";
	p = head2;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	p = head2;
	while(p)
	{
		if (p->randPtr)
			cout << "rand1: " << p->val << " --> "<< p->randPtr->val << endl;
		p = p->next;
	}
	deleteList(head2);


}
