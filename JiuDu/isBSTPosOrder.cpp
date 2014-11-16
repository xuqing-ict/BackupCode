#include <bits/stdc++.h>
using namespace std;

bool isPosOrder(const vector<int> &order, int left, int right)
{
    //one node

    if(right <= left) return true;

    int root = order[right];
    int i=left, leftEnd;
    for(;i<right;++i)
        if(order[i] > root)
            break;
    leftEnd=i-1;


    for(;i<right;++i)
        if(order[i]<root)
            return false;

    return isPosOrder(order,left,leftEnd) && isPosOrder(order,leftEnd+1,right-1);
}

int main()
{
    int N;
    vector<int> order;
    while(scanf("%d",&N) != EOF)
    {
        order.resize(N);
        for(int i=0;i<N;++i)
            scanf("%d",&order[i]);
        if(isPosOrder(order,0,N-1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
