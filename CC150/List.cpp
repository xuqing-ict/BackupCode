// Last Update:2014-07-10 09:54:19
/**
 * @file list.cpp
 * @brief 
 * @author Qing Xu xuqinguestc@163.com 
 * @version 0.1.00
 * @date 2014-06-08
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int _val):val(_val),next(NULL){}
};

ListNode *create(int data[], int n)
{
  if(data == NULL || n <= 0) return NULL;
  ListNode dummy(-1);
  ListNode *temp = &dummy;
  for(int i = 0 ; i <n ; ++i)
  {
    ListNode *node = new ListNode(data[i]);
    temp->next = node;
    temp = temp->next;
  }
  return dummy.next;
}
ListNode *reverse(ListNode *head)
{
  if(head == NULL || head->next == NULL) return head;
  ListNode dummy(-1);
  ListNode *rev = &dummy;
  ListNode *temp = NULL;
  while(head)
  {
    temp = head->next;
    head->next = rev->next;
    rev->next = head;
    head = temp;
  }
  return dummy.next;
}
void destory(ListNode * &head)
{
  if(head == NULL) return;
  while(head)
  {
    ListNode *temp = head->next;
    delete head;
    head = NULL;
    head = temp;
  }

}
void print(ListNode * head)
{
  while(head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
void reversePrint(ListNode *head)
{
  if(head == NULL) return;
  reversePrint(head->next);
  cout << head->val << " ";
}
void iterativeRevPrint(ListNode *head)
{
  if(head == NULL) return ;
  stack<int> s;
  while(head)
  {
    s.push(head->val);
    head = head->next;
  }
  while(!s.empty())
  {
    cout << s.top() << " " ;
    s.pop();
  }
  cout << endl;
}

ListNode *reverse2(ListNode *head)
{
  if(head == NULL) return head;
  ListNode *rev = NULL;
  
  while(head)
  {
    ListNode *temp = head->next;
    head->next =  rev;
    rev = head;
    head =  temp;
  }
  return rev;
}
ListNode *reverse3(ListNode *head)
{
  if(head == NULL) return head;
  ListNode dummy(0);
  while(head)
  {
    ListNode *temp = head->next;
    head->next = dummy.next;
    dummy.next = head;
    head = temp;
  }
  return dummy.next;
}
//number is stored reverse
ListNode *addTwoList(ListNode *num1, ListNode *num2)
{
  ListNode dummy(-1);
  ListNode *temp = &dummy;
  int carry = 0;
  int sum = 0;
  while(num1 && num2)
  {
    sum = num1->val + num2->val + carry;
    carry = sum/10;
    sum = sum%10;
    temp->next = new ListNode(sum);
    num1 = num1->next;
    num2 = num2->next;
    temp = temp->next;
  }
  ListNode *temp2 = NULL;
  if(num1) temp2 = num1;
  if(num2) temp2 = num2;

  while(temp2)
  {
    sum = temp2->val + carry;
    carry = sum/10;
    sum = sum%10;
    temp->next = new ListNode(sum);
    temp2 = temp2->next;
    temp = temp->next;
  }
  if(carry)
  {
    temp->next = new ListNode(1);
  }
  return dummy.next;
}
int len(ListNode *head)
{
  if(head == NULL) return 0;
  int n = 0;
  while(head)
  {
    ++n;
    head = head->next;
  }
  return n;
}
//insert node 0 at the head of the list
ListNode *paddle(ListNode *head, int n)
{
  if( n <= 0) return head;
  for(int i= 0 ; i < n ;++i)
  {
    ListNode *node =  new ListNode(0);
    node->next = head;
    head = node;
  }
  return head;
}
ListNode *addSameLenList(ListNode *num1, ListNode *num2, int &carry)
{
  if(num1 == NULL && num2 == NULL) return NULL;
  ListNode *next_sum = addSameLenList(num1->next, num2->next, carry);
  int sum = num1->val + num2->val + carry;
  carry = sum/10;
  sum = sum%10;
  ListNode *node = new ListNode(sum);
  node->next = next_sum;
  return node;
}

//the numbers are stored 
ListNode *addTwoNumbers(ListNode *num1, ListNode *num2)
{
  int n1 = len(num1);
  int n2 = len(num2);
  cout << "len : " << n1 << " " << n2 << endl;
  if(n1 < n2) swap(num1,num2);
  num2 = paddle(num2,abs(n1-n2));
  cout << "num1 : " ;print(num1);
  cout << "num2 : " ;print(num2);
  int carry=0;
  ListNode *ret = addSameLenList(num1,num2,carry);
  if(carry)
  {
    ListNode *node = new ListNode(1);
    node->next = ret;
    ret = node;
  }
  
  return ret;
} 

int main()
{
  int data[] = {3,4,5,6,7};
  int n = sizeof(data)/sizeof(int);
  ListNode *head =  create(data,n);
  print(head);
  reversePrint(head);
  iterativeRevPrint(head);
  cout << "reverse2..." << endl;
  ListNode *rev = reverse2(head);
  print(rev);
  destory(rev);
  int data1[] = {1};
  int n1 = sizeof(data1)/sizeof(int);
  int data2[] = {9};
  int n2 = sizeof(data2)/sizeof(int);
  ListNode *num1 = create(data1,n1);
  ListNode *num2 = create(data2,n2);
  ListNode *sum = addTwoList(num1,num2);
   destory(sum);
  sum = addTwoNumbers(num1,num2);
  
  print(sum);
  destory(sum);
  destory(num1);
  destory(num2);
  return 0;
}
