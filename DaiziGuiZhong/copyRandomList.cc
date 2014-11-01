/**
 * @file Candy.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>


struct ListNode
{
    int val;
    ListNode *next,*random;
    ListNode(int _val):val(_val),next(nullptr),random(nullptr){}
};

ListNode *copyList(ListNode *head)
{
    if(head == nullptr) return nullptr;
    //copy node and insert
    ListNode *tmp = head;
    while(tmp)
    {
        ListNode *node = new ListNode(tmp->val);
        node->next = tmp->next;
        tmp->next = node;
        tmp = node->next;
    }
    //copy random node
    tmp = head;
    while(tmp)
    {
        if(tmp->random) tmp->next->random = tmp->random->next;
        tmp = tmp->next->next;
    }
    //split
    ListNode dummy(0);
    ListNode *new_head = &dummy;
    tmp = head;
    while(tmp)
    {
        new_head->next = tmp->next;
        tmp->next = tmp->next->next;
        new_head = new_head->next;
        new_head->next = nullptr;
        tmp = tmp->next;
    }
    return dummy.next;
}

int main(void)
{

    return 0 ;
}
