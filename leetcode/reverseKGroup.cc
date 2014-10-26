/**
 * @file reverseKGroup.cc
 * @brief reverse k group in a singly list
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-22
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

void print(ListNode*);
inline int length(ListNode *head)
{
  int result = 0;
  while(head)
  {
    head = head->next;
    ++result;
  }
  return result;
}
/*
ListNode *reverseKGroup(ListNode *head, int k) {
  if(head == NULL) return head;
  if( k == 0 || k == 1) return head;

  int len = length(head);
  if(k > len) return head;
  int cycle = len/k;
  ListNode dummy(-1);
  ListNode *ret = NULL, *t_ret = NULL;
  while(cycle)
  {
    dummy.next = NULL;
    for(int i = 0 ; i< k ; ++i)
    {
      ListNode *t = head->next;
      head->next = dummy.next;
      dummy.next = head;
      head = t;
    }
    if(ret == NULL) 
    {
      ret = dummy.next;
    }
    else t_ret->next = dummy.next;

    t_ret = ret;
    while(t_ret->next)
    {
      t_ret = t_ret->next;
    }
    --cycle;
  }
  if(head) t_ret->next = head;
  return ret;
}
*/


ListNode *reverseKGroup(ListNode *head, int k)
{
  if(head == NULL || k < 2 ) return;
  ListNode *ret = NULL;
  ListNode dummy(-1);
  ListNode *prev = &dummy;
  ListNode *cur_head = head;
  while(1)
  {
  //find k nodes and reverse 
    cur_head = head;
    for(int i = 0 ; i < k-1 && head ; ++i)
    {
      head = head->next;
    }
    if(head == NULL) break;
    ListNode *tail = reverse(prev, cur_head, head);
    if(ret == NULL) ret = prev->next;
    prev = tail;
  }
  return ret;
}
void print(ListNode *head) 
{
  ListNode *temp = head;
  while(temp)
  {
    cout << temp->val<< " ";
    temp =  temp->next;
  }
  cout << endl;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  ListNode *temp = head->next;
  temp->next = new ListNode(3);
  temp = temp->next;
  temp->next = new ListNode(4);
  temp = temp->next;
  temp->next = new ListNode(5);

  cout << length(head) << endl;
  print(head);
  ListNode *rev = reverseKGroup(head,4);
  print(rev);

  return 0;
}
