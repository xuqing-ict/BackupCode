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

//此处相当于两个链表merge。因此必须保证两个链表最终都是以NULL结尾的
ListNode *insert(ListNode *new_list, ListNode *cur)
{
	ListNode *temp = NULL;
	ListNode *temp2 = NULL;
	temp = new_list;
	while(temp->next && temp->next->val <= cur->val)
	{
		temp = temp->next;
	}
	if(temp->next == NULL)
	{
		temp->next = cur;
		cur->next = NULL;//此处必须置为空，因为当前元素被放在了链表的尾部!!!!!!
	}
	else
	{
		temp2 =	temp->next;
		temp->next = cur;
		cur->next = temp2;
	}
	return new_list;

}




ListNode *sortList(ListNode *head)
{
	cout << "sortList " << endl;
	ListNode *new_list = new ListNode(-1);
	ListNode *cur = head;
	ListNode *cur_temp = NULL;
	while(cur)
	{
		cout << "cur = " << cur->val << endl;
		cur_temp = cur->next;
		insert(new_list,cur);
		cur = cur_temp;
	}
	ListNode *new_list_temp = new_list->next; 
	delete new_list;
	return new_list_temp;
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
