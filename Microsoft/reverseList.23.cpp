#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//求链表长度

int length(ListNode *head)
{
    if(head == NULL) return 0;
    int len = 0;
    while(head)
    {
        ++len;
        head = head->next;
    }
    return len;
}

//创建单链表，使用的是函数模板，针对不同的输入
template<class T>
ListNode *buildList(T beg, T end)
{
    if(beg ==  end) return NULL;
    ListNode *head = NULL, *prev = NULL;
    for(; beg != end ; ++beg)
    {
        ListNode *node = new ListNode(*beg);
        if(head == NULL)
        {
            head = node;
            prev = head;
        }
        else
        {
            prev->next = node;
            prev = node;
        }
    }
    return head;
}

//删除单链表，并且释放内存！！这是很重要的一步，否则将会导致内存泄露
void destoryList(ListNode *head)
{
    if(head == NULL) return;
    ListNode *next = head;
    while(head)
    {
        next  = head->next;
        delete head;
        head = next;
    }
}

//打印单链表
void printList(ListNode *head)
{
    if(head == NULL) cout << "EMPTY..." << endl;
    while(head)
    {
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
}
ListNode *reverseList(ListNode *head)
{
	ListNode *new_head = NULL, *temp = NULL;
	while(head)
	{
		temp = head->next;
		head->next = new_head;
		new_head = head;
		head = temp;
	}
	return new_head;
}
int main()
{
	int data[] = {1,2,3,4,5};
	int len =sizeof(data)/sizeof(int);
	ListNode *head = buildList(data,data + len);
	printList(head);
	ListNode *revHead = reverseList(head);
	printList(revHead);
	destoryList(revHead);
	return 0;
}
