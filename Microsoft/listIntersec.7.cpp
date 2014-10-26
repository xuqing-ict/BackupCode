/*
 * 微软亚院之编程判断俩个链表是否相交
 * 给出俩个单向链表的头指针,比如 h1,h2,判断这俩个链表是否相交。
 * 为了简化问题,我们假设俩个链表均不带环。
 * 问题扩展:
 * 1.如果链表可能有环列?
 * 2.如果需要求出俩个链表相交的第一个节点列?
 */

#include<iostream>

using namespace std;

struct listNode{
	int val;
	listNode *next;
	listNode(int x):val(x),next(NULL){}
};

listNode *buildList(int A[], int len, bool circle, int cross)
{
	cout << "build list = " << len << endl;
	listNode *head = NULL;
	listNode *pre = NULL;

	if (len == 0)return head;

	for(int i = 0 ; i < len ; ++i)
	{
		listNode *node = new listNode(A[i]);
		if( head == NULL )
		{
			head = node;
			pre = head;
			continue;
		}
		else
		{
			pre->next = node;
			pre = pre->next;
		}
	}

	cout << "print list..." << endl;
	pre = head;
	while(pre)
	{
		cout << pre->val << " ";
		pre = pre->next;
	}
	cout << endl;
	

	pre = head;
	listNode *tail = head;
	if (circle)
	{
		while(--cross)
			pre = pre->next;
		while( tail->next )
			tail = tail->next;

		tail->next = pre;
	}
	return head;
}




listNode *hasCircle(listNode *head)
{
	if(head == NULL)return NULL;

	listNode *fast = head;
	listNode *slow = head;
	
//	while(fast && fast->next && (fast != slow))
//	这样写是不对的，因为在初始的时刻fast就等于slow，循环根本就不会执行
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)return fast;
	}
//	if(fast == slow)return fast;
	return NULL;
}

listNode *findCirEntrance(listNode *head)
{
	if( head == NULL ) return NULL;

	listNode *start2 = hasCircle(head);
	if(start2 == NULL) return NULL;
	cout << "has circle!!!" << start2->val << endl;

	listNode *start1 = head;

	//has circle
	while(start1 != start2)
	{
		start1 = start1->next;
		start2 = start2->next;
	}
	if(start1 == start2)
		return start1;

}

bool twoListMerge(listNode *head1 , listNode *head2)
{
	while(head1->next)head1=head1->next;
	while(head2->next)head2=head2->next;
	return (head1==head2);

}

listNode *findMergeNode(listNode *head1 , listNode *head2)
{
	if(head1== NULL || head2 == NULL)return NULL;
	if (!twoListMerge(head1,head2))
	{
		cout << "two list no merge..." << endl;
		return NULL;
	}
	listNode *temp = head1;
	while(temp->next)temp = temp->next;
	temp->next = head2;
	return findCirEntrance(head1);
}



int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(A)/sizeof(int);
	
	bool circle = false;
	int cross = 5;

	listNode *head1 = buildList(A,len,circle,cross);

	listNode *temp = head1;
	while(temp && len--)
	{
		cout << temp->val <<" ";
		temp = temp->next;
	}
	if (temp != NULL)cout << temp->val << endl;	

	//find circle entrance
	listNode *enter = findCirEntrance(head1);

	if(enter) cout << "intersection node  = " <<  enter->val << endl;
	else cout << "NO..." << endl;

	int B[] = {-1,-2,-3,-4,-5};
	len = sizeof(B)/sizeof(int);
	listNode *head2 = buildList(B,len,circle,cross);

	temp = head2;
	while(temp->next)temp = temp->next;
	temp->next = head1->next->next;

	cout << "head1 = ";
	temp = head1;
	while(temp){cout << temp->val << " ";temp = temp->next;}
	cout << endl;
	
	cout << "head2 = ";
	temp = head2;
	while(temp){cout << temp->val << " ";temp = temp->next;}
	cout << endl;
	
	if (twoListMerge(head1 , head2))cout << "merged..." << endl;
	else	cout << "not merged..." << endl;

	temp = findMergeNode(head1,head2);
	cout << "merged node = " << temp->val << endl;
	return 0;
}
