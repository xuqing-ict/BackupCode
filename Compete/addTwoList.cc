//将两个用链表表示的数据相加，高位在链表头
//先补齐！！！
//再做 做完之后考虑进位
#include <iostream>
#include <iterator>
#include <assert.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


void destory(ListNode *head)
{
	ListNode *temp = NULL;
	while (!head)
	{
		temp = head->next;
		delete head;
		head = temp;
		
	}
}
void print(ListNode *head)
{
	cout << "print : ";
	while(head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

}
template<class forward_iterator>
ListNode *buildList(forward_iterator beg, forward_iterator end)
{
	ListNode *head = NULL, *temp = NULL;
	if(beg == end) return head;
	for(; beg != end; ++beg)
	{
		ListNode *node = new ListNode(*beg);
		if(temp)
		{
			temp->next = node;
			temp = temp->next;
		}	
		else
		{
			head = node;
			temp = head;
		}
	}
	return head;
}

int length(ListNode *L)
{
	int len = 0;
	while(L)
	{
		++len;
		L = L->next;
	}
	return len;
}

ListNode *helper(ListNode *L , ListNode *R, int &carry)
{
	if(L == NULL && R == NULL) return NULL;

	ListNode *head = helper(L->next, R->next, carry);

	int sum =  L->val + R->val + carry;
	carry = sum/10;
	sum = sum%10;
	ListNode *node = new ListNode(sum);
	node->next = head;
	head = node;

	return head;
}

ListNode *addNodes(ListNode * head, int len)
{
	cout << "addNodes ... " << endl;
	assert(len > 0);

	while(len-- > 0)
	{
		ListNode *node = new ListNode (0);
		node->next = head;
		head = node;
	}
	return head;
}


void Paddle(ListNode * & L , ListNode * & R)
{
	int lLen = length(L);
	int rLen = length(R);
	cout << "L len : "  << lLen << endl;
	cout << "R len : "  << rLen << endl;
	if(lLen == rLen)
	{
		return;
	}
	else if(lLen > rLen )
	{
		R = addNodes(R, lLen - rLen);
	}
	else
	{
		L = addNodes(L, rLen - lLen);
	}

}

ListNode *addTwoList(ListNode *L, ListNode *R)
{
	if(L == NULL) return R;
	if(R == NULL) return L;

	ListNode *head = NULL, *tL = L, *tR =R;

	ListNode dummy(-1);
	head = &dummy;

	Paddle(L, R);
	
	cout<< "Paddle end : " << endl;
	print(L);print(R);
	int carry = 0;

	head->next = helper(L,R, carry);
	
	head = dummy.next;

	if(carry == 1)
	{
		ListNode *node = new ListNode(1);
		node->next = head;
		head = node;
		dummy.next = head;
	}

	return dummy.next;
	
}

int main()
{
	int A[] = {9,9,9};
	int B[] = {};

	ListNode *L = buildList(A, A + sizeof(A)/sizeof(int));
	ListNode *R = buildList(B, B + sizeof(B)/sizeof(int));

	print(L);
	print(R);

	ListNode *ret = addTwoList(L, R);
	print(ret);

	return 0;
}
