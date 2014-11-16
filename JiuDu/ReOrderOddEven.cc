#include <bits/stdc++.h>
using namespace std;

bool isEven(int x)
{
    return !(x&1);
}

void reorder(int *pData, const unsigned int len, bool (*func)(int) )
{
    if(pData == nullptr || len < 2) return;
    int *pLeft = pData;
    int *pRight = pData + len-1;
    while(pLeft<pRight)
    {
        while(pLeft < pRight && !func(*pLeft)) ++pLeft;
        while(pLeft < pRight && func(*pRight)) --pRight;
        if(pLeft < pRight)
        {
            swap(*pLeft, *pRight);
            ++pLeft;
            --pRight;
        }
    }
}
int main(void)
{
    int A[] = {};
    const unsigned int n = sizeof(A)/sizeof(int);
    copy(A,A+n,ostream_iterator<int>(cout,"\t"));
    cout << endl;

    reorder(A,n,isEven);

    copy(A,A+n,ostream_iterator<int>(cout,"\t"));
    cout << endl;
    return 0;
}
