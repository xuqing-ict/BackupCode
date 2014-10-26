#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode *buildList(int *beg, int *end)
{
	ListNode *head = NULL, *temp = NULL;
	if(beg == end) return head;
	for(; beg != end ; ++ beg)
	{
		ListNode *node = new ListNode(*beg);
		if(head == NULL)
		{
			head = node;
			temp = head;
		}
		else
		{
			temp->next = node;
			temp = node;
		}

	}
	return head;
}

void printList(ListNode *head)
{
	while(head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int length(ListNode *head)
{
	int len = 0;
	while(head)
	{
		++len;
		head = head->next;
	}
	return len;
}
void destoryList(ListNode *head)
{
	ListNode *temp = head;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}
//P1 : delete head node but not free
ListNode* deleteNode(ListNode *head , int target)
{
	if(head == NULL) return head;

	ListNode *temp = head, *cur = head;
	//head node == target
	if(cur->val == target) 
	{
		temp = cur->next;
		delete cur;
		return temp;
	}

	while(cur->next)
	{
		if(cur->next->val == target)
		{
			temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}	

// return the k-th node from last
ListNode * nthFromLast(ListNode *head, int k)
{
	if (k <= 0) return  NULL;
	//fast and slow 
	ListNode *fast = head, *slow = head;
	while(k > 0)
	{
		if (fast == NULL ) 
		{
			return NULL;
		}
		--k;
		fast = fast->next;
	}

	while(fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


ListNode *reverse(ListNode *head)
{
	if(head == NULL) return head;

	ListNode dummy(-1);
	ListNode *new_head = &dummy, *prev = NULL;
	ListNode *temp = NULL;

	while(head)
	{
		temp = new_head->next ;
		new_head->next = head;
		prev = head->next;
		head->next = temp;
		head = prev;
	}
	return new_head->next;
}

int main()
{
	int data[] = {1,2,3,4};
	ListNode * myList = buildList(data,data+sizeof(data)/sizeof(int));
	printList(myList);
	int len = length(myList);
	cout << "len : " << len << endl;
	myList = deleteNode(myList,2);
	cout << "del 2 : " ;
	printList(myList);
	ListNode *k_thNode = nthFromLast(myList,3);

	if(k_thNode) cout << k_thNode->val << endl;
	else {cout << "k is invalid!!!" << endl;}
	ListNode *revList = reverse(myList);
	cout << "reverse : ";
	printList(revList);
	destoryList(myList);
	return 0;
}
