#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
bool isPalindrome(ListNode *head)
{
	if(head == NULL || head->next == NULL) return true;
	stack<ListNode *> s;
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		s.push(slow);
		slow = slow->next;
	}
	if(fast)
	{
		slow = slow->next;
	}
	while(!s.empty() && slow)
	{
		ListNode *node = s.top();
		s.pop();
		if(node->val != slow->val)
		{
			return false;
		}
		else
		{
			slow = slow->next;
		}
	}
	return true;
}
int  main()
{
	ListNode *head = new ListNode(0);
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node4 = new ListNode(1);
	ListNode *node5 = new ListNode(0);
	head->next = node1;
	node1->next = node2;
	node2->next = node4;
	node4->next = node5;

	if(isPalindrome(head))
	{
		cout << "is palindrome!!!" << endl;
	}
	else
	{
		cout << "not palindrome!!!" << endl;
	}
	return 0;
}
