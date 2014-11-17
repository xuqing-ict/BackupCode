/**
 * @file LRUCache.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-16
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
using namespace std;

class LRUCache{
private:
    struct ListNode
    {
        int key,value;
        ListNode *prev,*next;
        ListNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
    };
    typedef unordered_map<int, ListNode *>::iterator iter;
    int size;
    int capacity;
    unordered_map<int, ListNode *> mymap;
    ListNode *head;
private:
    void moveToHead(ListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addToHead(node);
    }
    void addToHead(ListNode *node)
    {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void delTail()
    {
        ListNode *p = head->prev;
        p->prev->next = head;
        head->prev = p->prev;
        iter it = mymap.find(p->key);
        mymap.erase(it);
        delete p;
        p = nullptr;
    }
public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        head = new ListNode(0,0);
        head->next = head;
        head->prev = head;
    }
    ~LRUCache()
    {
        ListNode *p = head->next, *q = nullptr;
        while(p!=head)
        {
            q = p->next;
            delete p;
            p = nullptr;
            p = q;
        }
        delete head;
        head = nullptr;
    }

    int get(int key) {
        iter it = mymap.find(key);
        if(it == mymap.end()) 
        {
            return -1;
        }
        else 
        {
            moveToHead((*it).second);
            return ((*it).second)->value;
        }
    }
    void set(int key, int value) {
        iter it = mymap.find(key);
        if(it != mymap.end())
        {
            it->second->value = value;
            moveToHead((*it).second);
        }
        else
        {
            ListNode *node = new ListNode(key,value);
            if(size == capacity){delTail(),--size;};
            addToHead(node);
            mymap.insert(make_pair(key,node));
            ++size;
        }
    }
};

int main(void)
{
    LRUCache l(1);
    l.set(2,1);
    cout << l.get(1) << endl;
    return 0 ;
}
