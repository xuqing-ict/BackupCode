#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};
class List
{
private:
  ListNode *head;
  void helper(ListNode *temp, const int k, int &cur);
public:
  List():head(NULL){}
  List(const vector<int> &);
  void reverse();
  void deleteNode(int );
  void print() const;
  void permute();
  void delRepeatNode();
  void printKNode(const int k);
  //void recursivePrintKthNode(const int k);
  void partition(const int value);
  void partition2(const int value);
  ~List();
private:
  void createList(const vector<int> &);
  void destory();
};

List::List(const vector<int> &data)
{
  createList(data);
}
void List::createList(const vector<int> &data)
{
  if(data.empty()){ head = NULL; return;}
  ListNode *temp = NULL;
  head = NULL;
  for(int i = 0 ; i< data.size(); ++i)
  {
    ListNode *node = new ListNode(data[i]);
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
}

void List::print() const
{
  ListNode *temp = head;
  while(temp)
  {
    cout << temp->val<< " ";
    temp =  temp->next;
  }
  cout << endl;
}
//a1 a2 a3 b1 b2 b3 ==> a1 b21 a2 b2 a3 b3
//fast = head->next, slow = head;
//Left segment'end shoule be set NULL!!
void List::permute()
{
  if(head == NULL || head->next == NULL) return;
  ListNode *slow = head;
  ListNode *fast = head->next;

  while(fast && fast->next)
  {
    fast=fast->next->next;
    slow=slow->next;
  }
  fast=slow->next;
  slow->next=NULL;
  slow=head;

  ListNode *new_head = NULL,*tempL = NULL, *tempR = NULL;
  ListNode *temp = NULL;
  while(fast && slow)
  {
    if(new_head == NULL) 
    {
      tempR = fast->next;
      tempL = slow->next;

      new_head = slow;
      new_head->next = fast;
      temp = fast; 
    }
    else
    {
      tempL = slow->next;
      tempR = fast->next;
      temp->next = slow;
      temp->next->next = fast;
      temp =fast; 
    }
    fast=tempR;
    slow=tempL;
  }
  if(slow)temp->next=slow;
  else temp->next=fast;
  head=new_head;
  return;
}
void List::delRepeatNode()
{
  if(head == NULL || head->next == NULL) return;
  ListNode *temp = head;
  unordered_set<int> occur;
  occur.insert(head->val);
  while(temp->next)
  {
    if(occur.find(temp->next->val) != occur.end())
    {
      ListNode *node = temp->next;
      temp->next = node->next;
      delete node;
      node = NULL;
    }
    else
    {
      occur.insert(temp->next->val);
      temp=temp->next;
    }
  }
}
void List::printKNode(const int k)
{
  if(head == NULL || k <= 0) return;
  ListNode *fast = head;
  for(int i = 0 ; i < k;++i)
  {
    if(fast == NULL)
    {
      cout << " K is too large" << endl;
      return;
    }
    fast = fast->next;
  }
  ListNode *temp = head;
  while(fast && temp)
  {
    temp=temp->next;
    fast=fast->next;
  }
  cout << "reverse: " << k << "-th Node : " << temp->val << endl;

}
/*
   void List::recursivePrintKthNode(const int k)
   {
   if(head == NULL || k <= 0) return;
   int cur=0;
   ListNode *temp =head;
   helper(temp,k,cur);
   }
   void List::helper(ListNode *temp,const int k , int &cur)
   {
   if(temp==NULL){cur=0;return;}

   helper(temp,k,++cur);
   if(cur == k )
   {
   cout << k << "-th Node : " << temp->val << endl;
   return;
   }
   }
   */
void List::partition2(const int value)
{
  if(head == NULL) return ;
  ListNode LHead(-1), RHead(-1);
  ListNode *tempL = &LHead, *tempR = &RHead;
  while(head)
  {
    if(head->val >= value)
    {
      tempR->next = head;
      tempR =  tempR->next;
      head = head->next;
    }
    else
    {
      tempL->next = head;
      tempL = tempL->next;
      head = head->next;
    }
  }
  tempR->next= NULL;
  tempL->next = RHead.next;
  head = LHead.next;
}
void List::partition(const int value)
{
  if(head == NULL) return;

  ListNode *L = NULL, *R= NULL;
  ListNode *tempL=NULL,*tempR=NULL;
  while(head)
  {
    if(head->val >= value)
    {
      if(R == NULL)
      {
        R = head;
        tempR=head;
        head=head->next;
      }
      else
      {
        tempR->next = head;
        tempR=tempR->next;
        head=head->next;
      }
    }
    else
    {
      if(L == NULL)
      {
        L = head;
        tempL=head;
        head=head->next;
      }
      else
      {
        tempL->next = head;
        tempL=head;
        head=head->next;
      }
    }
  }
    if(tempR)tempR->next=NULL;
    if(tempL)tempL->next=R;
    if(L)head=L;
    else head=R;
}
void List::destory() 
{
  ListNode *temp = head;
  while(head)
  {
    temp = head->next;
    delete head;
    head = NULL;
    head = temp;
  }
}

List::~List()
{
  destory();
}
void List::reverse()
{
  if(head == NULL || head->next == NULL) return;
  ListNode dummy(-1);
  ListNode *new_head = &dummy;

  while(head)
  {
    ListNode *temp = head->next;
    head->next = new_head->next;
    new_head->next = head;
    head = temp;
  }
  head = new_head->next;
}
void List::deleteNode(int target)
{
  ListNode *temp = head;
  //empty List
  if(head == NULL) return;
  //head node  == target
  if(head->val == target) 
  {
    head = head->next;
    delete temp;
    temp = NULL;
    return;
  }

  //other case
  while(temp->next && temp->next->val != target)
    temp = temp->next;
  if(temp->next == NULL) return;
  ListNode *delNode = temp->next;
  temp->next = temp->next->next;
  delete delNode;
  delNode = NULL;
  return;
}
