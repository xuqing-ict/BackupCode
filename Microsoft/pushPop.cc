/**
 * @file pushPop.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-28
 */
//判断一给定的pop与push序列是否一致
#include <bits/stdc++.h>
using namespace std;

bool valid(const vector<int> &push, const vector<int> &pop)
{
    const int n = push.size();
    assert(n == pop.size());

    stack<int> s;
    int push_index=0,pop_index=0;
    while(push_index < n)
    {
        if(!s.empty() && s.top() == pop[pop_index])
        {
            s.pop();
            ++pop_index;
        }
        else
        {
            s.push(push[push_index]);
            ++push_index;
        }
    }
    while(!s.empty() && s.top() == pop[pop_index]){s.pop();pop_index++;}
    return s.empty() && pop_index == n;
}

int main(void)
{
    int N;
    vector<int> push,pop;
    while(scanf("%d\n",&N)!=EOF)
    {
        push.resize(N);
        pop.resize(N);
        for(int i=0;i<N;++i)
            scanf("%d",&push[i]);
        for(int i=0;i<N;++i)
            scanf("%d",&pop[i]);
       if(valid(push,pop))
           printf("Yes\n");
       else
           printf("No\n");
    }
    return 0;
}
