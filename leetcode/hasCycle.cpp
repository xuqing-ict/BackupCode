//给定一个单链表，判断该单链表是否存在环。如果存在环，找出该环的入口。
//注意循环的起点！！！
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


void deleteList(ListNode *head)
{
	cout << "delete..." << endl;
	ListNode *temp = NULL;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

bool hasCycle(ListNode *head)
{
	if(!head)return false;
	ListNode *doubPtr = head->next;//此处使用next指针，主要是为了避免在在单链表且只有一个元素时的判断与其他的情况统一起来。
	ListNode *singPtr = head;
	while(doubPtr && doubPtr->next && singPtr && (doubPtr != singPtr))
	{
		assert(doubPtr && singPtr);
    	doubPtr = doubPtr->next->next;
	    singPtr = singPtr->next;
	}
	if (singPtr && doubPtr && (doubPtr == singPtr)) return true;
	else return false;
}
ListNode *hasCycle2(ListNode *head)
{
	if(!head)return NULL;
	ListNode *doubPtr = head->next;
	ListNode *singPtr = head;
	while(doubPtr && singPtr && (doubPtr != singPtr))
	{
		assert(doubPtr && singPtr);
    	doubPtr = doubPtr->next->next;
	    singPtr = singPtr->next;
	}
	if (singPtr && doubPtr && (doubPtr == singPtr)) return singPtr;
	else return NULL;
}
//是上述hasCycle的扩展 ，上述只是用来判断是否存在环，此处要返回环的起点的位置。
ListNode *detectCycle(ListNode *head)
{
	cout << "detect cycle..." << endl;
	ListNode *start2 = hasCycle2(head);
	start2 = start2->next; //这里指向next主要是为了跟上面的hasCycle中的doubPtr = head->next相对应，否则这两个指针永远都不会相遇。
	cout << "has Cycle 2 = " << start2->val << endl;

	if (!start2)return NULL;
	ListNode *start1 = head;
	while(start1 && start2 && start1 != start2)
	{
		start1 = start1->next;
		start2 = start2->next;
	}
	if(start1 == start2)
	{
		return start1;
	}
	
}


int main()
{	
	//srand(time(NULL));
	//int len = rand()%10;
	//int *data = new int[len];
	int len = 7;
	int data[] = {1,2,3,4,5,6,7};	
	
	//for(int i = 0 ; i < len ; ++i)
		//data[i] = rand()%10;
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
	ListNode *pre = head;
	while(p)
	{
		cout << p->val << " ";
		pre = p;
		p = p->next;
	}
	pre->next = head->next->next;
	cout << endl;

	if (hasCycle(head))
	{
		cout << "has Cycle..." << endl;
	}
	ListNode *node;
	if (node = detectCycle(head))
	{
		cout << "start = " << node->val<< endl;
		cout << "has Cycle..." << endl;
	}
	else
	{
		cout << "ERROR!!!" << endl;
	}
	/*p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
*/
	
	//deleteList(head);
	head = NULL;
//	delete [] data;
}
