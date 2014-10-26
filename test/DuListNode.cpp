//该双向链表的最后一个指针指向头节点。！！！

#include<iostream>
#include<cstdlib>
#include<assert.h>

using namespace std;

struct DuListNode{
	int val;
	DuListNode *prev,*next;
	DuListNode(int x):val(x),prev(NULL),next(NULL){}
};

typedef DuListNode * DuListHead;

class DuList{
private:
//	DuListNode *prev;
//	DuListNode *next;
	int val;
	DuListHead head;
public:
	DuList();
	~DuList();

	//void Init();
	bool IsEmpty();
	void Clear();
	int Length();
	DuListNode *GetElem(int);
	void Insert(int, int);
	void Delete(int);
	void Traverse();
	void RevTraverse();
};
DuList::DuList()
{
	cout << "Construst..." << endl;
	head = new DuListNode(0);
	head->prev = head;
	head->next = head;
}

DuList::~DuList()
{
	if(head == NULL)return;
	DuListNode* q, *p = head->next;
	while(p != head)
	{
		q = p->next;
		delete p;
		p = q;
	}
	free(head); //head node
	head = NULL;
}

bool DuList::IsEmpty()
{
	if(head->next == head && head->prev== head)
		return true;
	else
		return false;
}

void DuList::Clear()
{
	DuListNode *q, *p = head->next;
	while(p != head)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = head;
	head->prev = head;
}

int DuList::Length()
{
	int i = 0;
	DuListNode *p = head->next;
	while(p != head)
	{
		i++;
		p = p->next;
	}
	return i;
}
DuListNode * DuList::GetElem(int i)
{
	int j = 1;
	DuListNode *p = head->next;
	while( p != head && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == head || j < i)
		return NULL;
	else
		return p;
}

void DuList::Insert(int i, int x)
{
	if(i<0)
		return;
	cout << "Insert..." << i << x << endl;
	DuListNode *node = new DuListNode(x);
	DuListNode *curPrev;
	if(i == 0)
		curPrev = head;
	else
		curPrev = GetElem(i-1);
	DuListNode *tNext = curPrev->next;
	node->next = tNext;
	tNext->prev = node;
	node->prev = curPrev;
	curPrev->next = node;
	return;
}
//delete node which number is value
void DuList::Delete(int x)
{
	DuListNode *q = head ,*p = head->next;
	while(p != head && p->val != x)
	{
		q = p;
		p = p->next;
	}
	if(p == head) 
		cout << "elem not exist.." << endl;
	else
	{
		assert(p->val == x);
		assert(q->next == p);
		q->next = p->next;
		p->next->prev = q;
		delete p;
		p = NULL;
	}
	return;
}

void DuList::Traverse()
{
	DuListNode *q, *p = head->next;
	while(p != head)
	{
		cout << p->val << " ";
		p = p ->next;
	}
	cout << endl;
}

void DuList::RevTraverse()
{
	DuListNode *p = head->prev;
	while( p != head)
	{
		cout << p->val <<  " ";
		p = p->prev;
	}
	cout << endl;
}
int main()
{
	
	DuList L1;
	if(L1.IsEmpty())
		cout << "L1 is empty..." << endl;
	L1.Insert(0,5);
	L1.Insert(0,3);
	L1.Insert(0,2);
	L1.Insert(0,1);
	L1.Insert(4,4);
	L1.Traverse();
	L1.RevTraverse();
	DuListNode *node(NULL);
	if(node = L1.GetElem(2))
		cout << node->val << endl;
	L1.Delete(2);
	L1.Traverse();
	L1.RevTraverse();

	return	EXIT_SUCCESS;
}
