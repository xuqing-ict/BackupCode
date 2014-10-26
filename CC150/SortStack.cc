/**
 * @file SortStack.cc
 * @brief sort stack only using another stack
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-13
 */

//sort stack only using another stack
#include <bits/stdc++.h>
using namespace std;
/*
   void merge(stack<int> &s, stack<int>& less, stack<int> &grt)
   {
   if(less.empty() && grt.empty()) return;

   }
   */

void sortStack(stack<int>& s)
{
    if(s.empty()) return;
    stack<int> temp;

    while(!s.empty())
    {
        int cur = s.top();
        s.pop();

        if(temp.empty())
        {
            temp.push(cur);
            continue;
        }
        while(!temp.empty())
        {
            if(temp.top() < cur) 
            {
                s.push(temp.top());
                temp.pop();
            }
            else
            {
                temp.push(cur);   
                break;
            }
        }
        if(temp.empty()) temp.push(cur);
    }
    s.swap(temp);
}


void quickSortStack(stack<int> &s)
{
    cout << "enter..." << endl;
    if(s.empty()) return;
    int pivot = s.top();s.pop();
    if(s.empty()) 
    {
        s.push(pivot);
        return;
    }
    stack<int> less, grt;
    while(!s.empty())
    {
        int cur = s.top();s.pop();
        if(cur <= pivot)
        {
            less.push(cur);
        }
        else
        {
            grt.push(cur);
        }
    }
    if(less.empty()) less.push(pivot);
    else grt.push(pivot);
    quickSortStack(less);
    quickSortStack(grt);
    while(!grt.empty())
    {
        s.push(grt.top());
        grt.pop();
    }

    while(!s.empty())
    {
        less.push(s.top());
        s.pop();
    }
    
    s.swap(less);
}

void merge(stack<int> &s, stack<int> &left, stack<int> &right)
{
    assert(s.empty());
    if(left.empty() && right.empty())
    {
        return ;
    }
    if(left.empty())
    {
        s.swap(right);
        return;
    }
    if(right.empty())
    {
        s.swap(left);
        return;
    }

    int l = left.top(); left.pop();
    int r = right.top(); right.pop();
    while(1)
    {
        if(l < r)
        {
            s.push(r);
            if(right.empty())
            {
                s.push(l);
                break;
            }
            r = right.top();right.pop();
        }
        else
        {
            s.push(l);
            if(left.empty())
            {
                s.push(r);
                break;
            }
            l = left.top(); left.pop();
        } 

    }
    while(!left.empty())
    {
        l = left.top(); left.pop();
        s.push(l);
    }
    while(!right.empty())
    {
        r = right.top(); right.pop();
        s.push(r);
    }
    while(!s.empty()) {
        right.push(s.top()); s.pop();
    }
    right.swap(s);
}    

void mergeSortStack(stack<int> &s)
{
    //empty
    if(s.empty()) return;
    //single element
    //maybe a little weird
    int temp = s.top(); s.pop();
    if(s.empty()) {
        s.push(temp);
        return;
    }
    s.push(temp);

    stack<int> left, right;
    while(!s.empty())
    {
        int cur = s.top();s.pop();
        left.push(cur);
        if(s.empty()) break;
        cur = s.top(); s.pop();
        right.push(cur);
    }
    mergeSortStack(left);
    mergeSortStack(right);
    merge(s,left,right);
}
int main()
{
    stack<int> s;
    srand(time(NULL));
    for(int i=0; i<1000; ++i)
        s.push(rand() % 10000);
      /*
      sortStack(s);
        while(!s.empty())
        {
        cout << s.top() << " ";
        s.pop();
        }
        cout << endl;
        */
    //quickSortStack(s);
    mergeSortStack(s);
    int prev= INT_MAX;
    while(!s.empty())
    {
        cout << s.top() << " ";
        assert(s.top()<= prev);
        prev = s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}
