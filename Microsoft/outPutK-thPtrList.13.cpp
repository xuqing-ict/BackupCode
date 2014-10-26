//输出链表的倒数第k个节点，最后一个节点是第0个，因此两个节点之间应该相差k个节点，并且循环的终止节点应该是该节点的后继为空的时候
#include<iostream>
#include<cstdlib>

using namespace std;

struct ListNode{
	int m_key;
	ListNode *m_pNext;
	ListNode(int key):m_key(key),m_pNext(NULL){}
};

ListNode *outPutKthNode(ListNode *head , int k)
{
	if(head == NULL) return head;
	cout << "head = " << head->m_key << endl;
	ListNode *slow = head;
	ListNode *fast = head;
	while(fast && k) {fast = fast->m_pNext;k--;}
	//注意此处必须判断fast->m_pNext
	if (k == 0 )
	{
		while(fast && fast->m_pNext) 
		{
			fast = fast->m_pNext;
			slow = slow->m_pNext;
		}
		return slow;
	}
	cout << "k = " << k << endl;
	return NULL;
}

int main()
{

	ListNode *head = new ListNode(-1);
	int n = 12;
	ListNode *temp = head;
	for(int i = n ; i >= 0; --i)
	{
		ListNode *node = new ListNode(i);
		temp->m_pNext = node;
		temp = node;
	}

	cout << "list = ";
	temp = head;
	while(temp)
	{
		cout << temp->m_key << " ";
		temp = temp->m_pNext;
	}
	cout << endl;
	int k = 13;
	ListNode *ptr(NULL);
	if(ptr = outPutKthNode(head , k)) 
	{
		cout << ptr->m_key << " " << ptr->m_pNext->m_key <<  endl;
	}
	else
	{
		cout << "NO..." << endl;
	}

	while(head)
	{
		temp = head->m_pNext;
		delete head;
		head = temp;
	}
	return EXIT_SUCCESS;
	
}
