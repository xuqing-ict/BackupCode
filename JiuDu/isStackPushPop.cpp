#include <bits/stdc++.h>
using namespace std;

bool is_legal(const vector<int> &seq, const vector<int> &stack_seq)
{
    if(seq.empty() && stack_seq.empty()) return true;
    if(seq.empty()|| stack_seq.empty()) return false;

    stack<int> helper;
    int k=0; //record the index of stack_seq
    int i=0; //record the index of seq
    while(i < seq.size())
    {
        if(!helper.empty() && helper.top() == stack_seq[k])
        {
            helper.pop();
            k++;
        }
        else
        {
            helper.push(seq[i++]);
        }
    }
    //余下的部分！！
    while(!helper.empty())
    {
        if(helper.top() != stack_seq[k++])
            return false;
        helper.pop();
    }

    return true;
}

int main()
{
    int N;
    vector<int> seq, stack_seq;

    while(scanf("%d",&N) != EOF)
    {
        seq.resize(N);
        stack_seq.resize(N);
        for(int i=0;i<N;++i)
            scanf("%d",&seq[i]);
        for(int i=0;i<N;++i)
            scanf("%d",&stack_seq[i]);
        if(is_legal(seq,stack_seq))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
