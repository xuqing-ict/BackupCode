#include <bits/stdc++.h>
using namespace std;

int findFirstBit1(const int tmp)
{
    int i;
    for(i=0;i<32;++i)
        if(tmp & (1<<i))break;
    return i;
}

void findNumberOccurOnce(int *A,const int n,int &num1, int &num2)
{
    if(A == nullptr || n <= 0 ){num1=num2=0;return;}
    int tmp=0;
    for(int i=0;i<n;++i)
        tmp ^= A[i];
    int idx = findFirstBit1(tmp);
    num1=num2=0;
    for(int i=0;i<n;++i)
    {
        if(A[i] & (1<<idx)) num1 ^= A[i];
        else num2 ^= A[i];
    }
}
int main(void)
{
    /*
    int num1,num2;
    int A[] = {2,4,3,6,3,2,5,5};
    const int n = sizeof(A)/sizeof(int);
    findNumberOccurOnce(A,n,num1,num2);
    cout << num1 << "\t" << num2 << endl;
    */
    cout << sizeof(unsigned int) << endl;

    int n, num1, num2;

    while(scanf("%d",&n) != EOF)
    {
        int *A = new int[n];
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        findNumberOccurOnce(A,n,num1,num2);
        if(num1 > num2) swap(num1,num2);
        printf("%d\t%d\n",num1,num2);
        delete [] A;
    }
    return 0;
}
