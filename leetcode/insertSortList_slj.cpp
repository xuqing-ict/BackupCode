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

/*
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
		p = p->next; //bug p is already deleted
	}
	delete p;
	head = NULL;
}
*/
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


ListNode *sortList(ListNode *head)
{
	if (head == NULL)
		return head;

	ListNode *Head = new ListNode(MIN);
	Head->next = head;
	printList(Head);
	ListNode *cur = Head;

	ListNode *t = NULL;
	ListNode *t2 = NULL;
	ListNode *t3 = NULL;
	ListNode *t4 = NULL;

	while(cur->next)
	{   //每一步循环，cur指向的是前半部分（已排序）的最后一个节点，处理cur->next
		t = Head;
		t2 = cur->next;

		while(((t->next) != t2) && ((t->next)->val) <= t2->val) //保证当前的比较一定会在本节点处终止
			t = t->next;

		if (t->next == t2)
		{
			cur = cur->next;
			continue;
		}
		else
		{
		// 需要将cur指向前半部分（已排序)的最后一个节点，下一步循环处理的就是cur->next
			//t4 = cur->next; //错误！！cur->next这个节点会被插入到前面去，不再是前半部分的最后一个节点
			t4 = cur;//cur这个节点才是前半部分的最后一个节点
			//insert t2 into t->next之前
			cur->next = t2->next;
			t3 = t->next;
			t->next = t2;
			t2->next = t3;
			cur = t4;//备份cur的值。
		}
	}
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
